#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
const db PI = acos(-1);

ll r[N];
ll x[N];
ll y[N];
int n;
vector<int> T[N];
bool h1[N];

bool contain(int i, int j){ // check whethever j belongs to i
	ll s1 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	ll s2 = r[i] * r[i];
	return s1 <= s2;
}

void construct(int vert){
	h1[vert] = true;
	vector<pii> hh;
	for(int j = 0 ; j < n;j ++ ){
		if(vert == j)
			continue;
		if(contain(vert, j)){
			hh.push_back(mp(r[j], j));
		}
	}
	sort(hh.begin(), hh.end());
	for(int j = (int)hh.size() - 1;  j >= 0 ; j -- ){
		if(!h1[hh[j].se]){
			T[vert].push_back(hh[j].se);
			construct(hh[j].se);
		}
	}
}

ll dp[N][2][2];

bool viivi[N];

void dfs(int u){
	viivi[u] = true;
	ll cur[2][2];
	for(int i =0 ; i < 2; i ++ )for(int j =0 ; j < 2; j ++ )cur[i][j] = 0;
	for(auto x : T[u]){
		dfs(x);
		for(int i= 0 ; i < 2; i ++ ){
			for(int j = 0 ;j < 2; j ++ ){
				cur[i][j] += dp[x][i][j];
			}
		}
	}
	ll s1, s2;
	for(int i = 0 ;i < 2 ; i ++ ){
		for(int j = 0 ;j  < 2 ;j ++ ){
			s1 = cur[i^1][j] + (i == 0 ? +1 : -1) * r[u] * r[u];
			s2 = cur[i][j^1] + (j == 0 ? +1 : -1) * r[u] * r[u];
			dp[u][i][j] = max(s1, s2);
		}
	}
}

int main(){
	fastIO;
	cin >> n;
	vector<pii> rng;
	for(int i = 0 ; i < n; i ++ ){
		cin >> x[i] >> y[i] >> r[i];
		rng.push_back(mp(r[i], i));
	}
	sort(rng.begin(), rng.end());
	for(int i = rng.size() - 1; i >= 0 ; i  -- ){
		if(!h1[rng[i].se]){
			construct(rng[i].se);
		}
	}
	ll answ = 0;
	for(int i = rng.size() - 1; i >= 0 ; i -- ){
		if(!viivi[rng[i].se]){
			dfs(rng[i].se);
			answ += dp[rng[i].se][0][0];
		}
	}
	db ret = answ;
	ret *= PI;
	cout << fixed << setprecision(10) << ret;
	return 0;
}