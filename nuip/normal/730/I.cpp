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

bool chmax(int &a,const int &b){
	if( a < b ){
		a=b;
		return 1;
	}
	return 0;
}

int dp[3005][3005]={}, bf[3005][3005]={};
int a[3005], b[3005];
int main(){
	fill( dp[0], dp[0]+3005*3005, -MOD );
	fill( bf[0], bf[0]+3005*3005, 0 );
	int N, p, s;
	vector<pair<pii,int> > st;
	dp[0][0] = 0;
	
	cin >> N >> p >> s;
	rep(i,N) cin >> a[i];
	rep(i,N) cin >> b[i];
	rep(i,N) st.eb( pii(a[i], b[i]), i+1 );

	sort( all(st) );
	reverse( all(st) );

	rep(i,N) rep(k,s+1){
		if( chmax(dp[i+1][k],   dp[i][k] + (i-k<p ? st[i].X.X : 0) ) ) bf[i+1][k]   = k;
		if( chmax(dp[i+1][k+1], dp[i][k] + st[i].X.Y) ) bf[i+1][k+1] = k;
	}

	vector<int> ans[2];
	int bk = s;
	rrep(i,N){
		ans[ (bf[i+1][bk] != bk) ].pb( i );
		bk = bf[i+1][bk];
	}

	assert( ans[0].size() >= p );
	assert( dp[N][s] > 0 );
	reverse(all(ans[0]));
	ans[0].resize( p );

	cout << dp[N][s] << endl;
	for(auto t: ans[0]) cout << st[t].Y << " "; cout << endl;
	for(auto t: ans[1]) cout << st[t].Y << " "; cout << endl;

	return 0;
}