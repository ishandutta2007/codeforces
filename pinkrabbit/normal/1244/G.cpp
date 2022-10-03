#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,a[MN];ll ans,k;
int main(){
	scanf("%d%lld",&n,&k);
	if(k<(ll)n*(n+1)/2)return puts("-1"),0;
	k-=(ll)n*(n+1)/2;
	F(i,1,n)a[i]=i;
	F(i,1,n/2){
		if(k>n-i-i+1){swap(a[i],a[n-i+1]);k-=n-i-i+1;}
		else{swap(a[n-i+1],a[n-i+1-k]);break;}
	}
	F(i,1,n)ans+=max(i,a[i]);
	printf("%lld\n",ans);
	F(i,1,n)printf("%d%c",i," \n"[i==n]);
	F(i,1,n)printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}