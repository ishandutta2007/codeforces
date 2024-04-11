#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll m,n;
		scanf("%lld%lld",&n,&m);
		ll tot=n-m,ans=n*(n+1)/2,k=m+1;
		ll sum=tot/k,last=tot%k;
		//cout<<ans<<' '<<tot<<"ans\n";
		ans-=(sum+1)*(sum+2)/2*(last);
		ans-=(sum+1)*sum/2*(k-last);
		printf("%lld\n",ans);
	}
}