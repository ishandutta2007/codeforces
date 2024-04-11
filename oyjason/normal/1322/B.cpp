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
int n,p[M],H[M],C[2],a[M];
inline int solve(int k){
	int ans=0;
	C[0]=C[1]=0;
	for(int i=1;i<=n;i++) a[i]=p[i],C[(a[i]>>k)&1]++;
	C[1]+=C[0]; int r1=0,l2=1;
	for(int i=n;i>=1;i--) p[C[(a[i]>>k)&1]--]=a[i];
	while(l2<=n&&!((p[l2]>>k)&1)) l2++,r1++;
	// debug(k)sp,debug(r1)sp,debug(l2)el;
	// for(int i=1;i<=n;i++) printf("%d ",p[i]); cerr el;
	for(int i=1,bas=r1;i<=r1;i++){
		while(bas>i&&(((p[i]+p[bas])>>k)&1)) --bas;
		bas=max(bas,i),ans^=((r1-bas)&1);
	}
	// debug(ans)el;
	for(int i=l2,bas=n;i<=n;i++){
		while(bas>i&&(((p[i]+p[bas])>>k)&1)) --bas;
		bas=max(bas,i),ans^=((n-bas)&1);
	}
	// debug(ans)el;
	for(int i=1,bas=n;i<=r1;i++){
		while(bas>r1&&!(((p[i]+p[bas])>>k)&1)) --bas;
		// debug(i)sp,debug(bas)el;
		ans^=((bas-r1)&1);
	}
	// fgx;
	return ans;
}
int main(){
	n=read();
	int ans=0;
	for(int i=1;i<=n;i++) p[i]=read(),a[i]=p[i];
	for(int i=0;i<30;i++) ans^=(solve(i)<<i);
	printf("%d\n",ans);
	return 0;
}