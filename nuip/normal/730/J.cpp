#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

pii dp[11234];

int main(){
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	fill(dp,dp+11234,pii(200,0));
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>b[i];
	dp[0]=pii();
	rep(i,n){
		rrep(j,10234) dp[j+b[i]]=min(dp[j+b[i]], pii(dp[j].X+1,dp[j].Y-a[i]));
		rrep(j,10234) dp[j]=min(dp[j],dp[j+1]);
	}
	int sum=accumulate(all(a),0);
	//rep(i,5) cout<<dp[i].X<<":"<<dp[i].Y<<","; cout<<endl;
	cout<<dp[sum].X<<" "<<sum+dp[sum].Y<<endl;
	return 0;
}