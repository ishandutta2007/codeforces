#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define DB long double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define rint register int 
inline int read(){
	int nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 200200
int n,m,k,p,ct[M];
LL Mx,A[M],H[M],G[M],ans,t[M];
inline bool check(LL X){
	LL tot=0; memset(ct,0,sizeof(ct));
	for(int i=1;i<=n;i++) tot+=(t[i]=((max(G[i]-X,0ll)+p-1)/p));
	if(tot>k*m) return false;
	for(int i=1;i<=n;i++) if(t[i]>0){
		for(LL Rgt=(G[i]-X+p-1)%p+1-H[i]+A[i];t[i]--;Rgt+=p){
			if(Rgt<0){++ct[1];continue;} LL tar=(Rgt+A[i]-1)/A[i];
			if(tar>m) return false; ++ct[tar];
		}
	}
	for(int i=m,opr=0;i>0;i--){
		ct[i]+=ct[i+1],opr+=k;
		if(ct[i]>opr) return false;
	} return true;
}
int main(){
	n=read(),m=read(),k=read(),p=read();
	for(int i=1;i<=n;i++) H[i]=read(),A[i]=read(),Mx=max(Mx,G[i]=(H[i]+m*A[i])); ans=Mx;
	for(LL l=0,r=Mx-1,mid=((l+r)>>1);l<=r;mid=((l+r)>>1))
		if(check(mid)) ans=mid,r=mid-1; else l=mid+1;
	printf("%lld\n",ans); return 0;
}