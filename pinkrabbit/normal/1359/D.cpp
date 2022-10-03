#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,a[MN],s1[17][MN],s2[17][MN];
int L[MN],R[MN],stk[MN],tp;
int ans;
inline int ask1(int l,int r){
	int j=31-__builtin_clz(r-l+1);
	return max(s1[j][r],s1[j][l+(1<<j)-1]);
}
inline int ask2(int l,int r){
	int j=31-__builtin_clz(r-l+1);
	return min(s2[j][r],s2[j][l+(1<<j)-1]);
}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),s1[0][i]=s2[0][i]=s1[0][i-1]+a[i];
	for(int j=0;2<<j<=n+1;++j)
		F(i,(1<<j)-1,n)
			s1[j+1][i]=max(s1[j][i],s1[j][i-(1<<j)]),
			s2[j+1][i]=min(s2[j][i],s2[j][i-(1<<j)]);
	a[0]=inf,stk[tp=1]=0;
	F(i,1,n){
		while(a[stk[tp]]<=a[i])R[stk[tp--]]=i-1;
		L[i]=stk[tp]+1,stk[++tp]=i;
	}while(tp)R[stk[tp--]]=n;
	F(i,1,n){
		int res=ask1(i,R[i])-ask2(L[i]-1,i-1)-a[i];
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}