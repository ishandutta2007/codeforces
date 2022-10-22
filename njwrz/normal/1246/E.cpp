#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
bitset<2005> dp[1<<16];
int n,k;
int a[16];
V<int> v[2005];
void dfs(int x,int val,int dep){
	if(!x)RE ;
	rep(i,0,n)if(x&(1<<i))if(val>=a[i]&&dp[x-(1<<i)][val-a[i]]){
		v[dep].PB(a[i]);
		dfs(x^(1<<i),val-a[i],dep);
		RE;
	}
	dfs(x,val*k,dep+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	int sum=0;
	rep(i,0,n)cin>>a[i],sum+=a[i];
	dp[0][0]=1;
	rep(mask,1,1<<n){
		rep(i,0,n)if(mask&(1<<i))dp[mask]|=dp[mask^(1<<i)]<<a[i];
		for(int i=sum/k*k;i>=k;i-=k)if(dp[mask][i])dp[mask][i/k]=1;
	}
	if(dp[(1<<n)-1][1]==0){
		cout<<"NO";RE 0;
	}
	dfs((1<<n)-1,1,0);
	V<P<int,int> > ans;
	for(int i=sum;i>=0;i--)if(!v[i].empty()){
		int sum=0;
		for(auto u:v[i]){
			if(sum)ans.PB(MP(sum,u));
			sum+=u;
			if(sum%k==0){
				int pos=i;
				while(sum%k==0)sum/=k,pos--;
				v[pos].PB(sum);
				sum=0;
			}
		}
	}
	cout<<"YES\n";
	for(auto u:ans)cout<<u.F<<' '<<u.S<<'\n';
	RE 0;
}