#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int MOD = (int)1e9 + 7;
vector<int> T[N];

int x[N];
int dp[N][2];

int compute(vector<pii> ch){
	int n = ch.size();
	int suf[n + 1];
	suf[n] = 1;
	for(int i = n - 1; i >= 0 ; i -- ){
		suf[i] = (1ll * suf[i + 1] * ((ch[i].fi + ch[i].se) % MOD)) % MOD;
	}
	int pref = 1ll;
	int sum = 0;
	for(int i = 0 ; i < n; i ++ ){
		sum = (sum + ((((1ll * pref * ch[i].se) % MOD) * 1ll * suf[i + 1])) % MOD) % MOD;
		pref = (1ll * pref * ((ch[i].fi + ch[i].se) % MOD)) % MOD;
	}
	return sum;
}

void dfs(int u){
	vector<pii> xl;
	int zer = 1;
	for(auto x : T[u]){
		dfs(x);
		xl.push_back(mp(dp[x][0], dp[x][1]));
		zer = (1ll * zer * ((dp[x][0] + dp[x][1]) % MOD)) % MOD;
	}
	if(x[u] == 1){
		dp[u][1] = zer;
	}
	else{
		dp[u][0] = zer;
		dp[u][1] = compute(xl);
	}
}

int main(){
	fastIO;
	int n;
	cin >> n;
	int p;
	for(int i = 1; i < n; i ++ ){
		cin >> p;
		T[p].push_back(i);
	}
	for(int i = 0 ; i < n; i ++ ){
		cin >> x[i];
	}
	dfs(0);
	cout << dp[0][1];
	return 0;
}