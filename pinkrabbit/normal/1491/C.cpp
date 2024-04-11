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
int n;
int a[MN];
ll b[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),b[i]=0;
	ll ans=0;
	F(i,1,n){
		b[i]+=b[i-1];
		ll cnt=b[i];
		if(b[i]<a[i]-1){
			ans+=a[i]-1-b[i];
			cnt=a[i]-1;
		}
		if(i==n){
			a[i]=1;
			break;
		}
		if(i+a[i]>n){
			cnt-=i+a[i]-n;
			a[i]=n-i;
		}
		++b[i+2];
		--b[i+a[i]+1];
		cnt-=a[i]-1;
		b[i+1]+=cnt;
		b[i+2]-=cnt;
	}
	printf("%lld\n",ans);
}	return 0;
}