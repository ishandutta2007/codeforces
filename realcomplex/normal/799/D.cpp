#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll N = 50;
const ll M = (int)1e5 + 9;
vector<ll> mlt;
ll dp[M][N];

int calc(ll w, ll h, ll a, ll b){
	for(ll i = 0 ; i < M ; i ++ ) for(ll j = 0 ; j < N ; j ++ )
		dp[i][j] = 0;
	w = min(w, a);
	h = min(h, b);
	dp[w][0] = h;
	ll m = mlt.size();
	ll nz;
	for(ll x = w; x <= a; x ++ ){
		for(ll j = 0 ; j < m ; j ++ ){
			nz = min(x * mlt[j], a);
			dp[nz][j + 1] = max(dp[nz][j + 1], dp[x][j]); 
			nz = min(dp[x][j] * mlt[j], b);
			dp[x][j + 1] = max(dp[x][j + 1], nz);
		}
	}
	for(ll j = 0 ; j <= m; j ++ ){
		if(dp[a][j] == b){
			return j;
		}
	}
	return (ll)1e9;
}

int main(){
	fastIO;
	ll h, w, a, b;
	ll n;
	cin >> a >> b >> h >> w >> n;
	ll y;
	for(int i = 0 ; i < n; i ++ ){
		cin >> y;
		mlt.push_back(y);
	}
	sort(mlt.begin(), mlt.end());
	reverse(mlt.begin(), mlt.end());
	while(mlt.size() > 40){
		mlt.pop_back();
	}
	ll z = min(calc(h, w, a, b), calc(h, w, b, a));
	if(z == (ll)1e9)
		cout << -1 << "\n";
	else
		cout << z << "\n";
	return 0;
}