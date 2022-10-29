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
#define all(x) x.begin(),x.end()
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int b[N];
map<int,ll> sum;
int main(){
	int n;
	ll ans=0;
	scanf("%d",&n);
	rep(i,1,n+1){
		scanf("%d",&b[i]);
		sum[b[i]-i]+=b[i];
		ans=max(ans,sum[b[i]-i]);
	}
	printf("%lld\n",ans);
}