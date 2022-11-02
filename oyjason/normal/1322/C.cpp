#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 2200020
ULL seed=115862374543532551llu;
inline ULL RD(){return seed=(seed<<11)^(seed<<27)^(seed>>31)^(rand()<<7)^(rand()<<17);}
int fs[M],nt[M],to[M],tmp,n,m,id[M];
LL c[M],ans;
ULL val[M],w[M];
inline bool cmp(int x,int y){return w[x]<w[y];}
inline LL solve(){
	ans=0,n=read(),m=read();
	for(int i=1;i<=n;i++) val[i]=RD(),w[i]=0,id[i]=i,c[i]=read();
	for(int i=1,x,y;i<=m;i++) x=read(),y=read(),w[y]^=val[x];
	sort(id+1,id+n+1,cmp);
	for(int l=1,r=0;l<=n;l=r+1){
		LL now=0;
		while(r<n&&w[id[r+1]]==w[id[l]]) ++r,now+=c[id[r]];
		if(w[id[l]]!=0) ans=__gcd(ans,now);
	} return ans;
}
int main(){
	srand(19260817);
	for(int Cas=read();Cas;--Cas) printf("%lld\n",solve());
	return 0;
}