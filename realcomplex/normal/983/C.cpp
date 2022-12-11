#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;
const int M = (int)1e5 + 9;
const int W = 715;

int cnt = 0;
int pi[M];
vector<int> T[W];
int id[W];

void f(vector<int> t, int ls);
void init();

int dp[N][W][10];

int dis(int a, int b){
	return max(a-b, b-a);
}

int new_state(int state, int cl, int cr){
	int hsh = 0, pw = 1;
	for(int j = 0 ; j < T[state].size(); j ++ ){
		if(T[state][j] >= cl && T[state][j] <= cr)	
			continue;
		hsh += T[state][j] * pw;
		pw *= 13;
	}
	return pi[hsh];
}

void upd(int &a, int b){
	a = min(a, b);
}

int main(){
	fastIO;
	init();
	for(int i = 0 ; i < N ; i ++ )
		for(int j = 0 ; j < W; j ++ )
			for(int z = 0; z < 10 ; z ++ )
				dp[i][j][z] = (int)1e9;
	for(int j = 1 ; j <= 9 ; j ++ )
		dp[0][0][j] = j - 1;
	int n;
	cin >> n;
	int a, b;
	bool ok;
	int sm;
	int pw;
	int li, ri;
	int dist;
	int cur;
	for(int i = 1; i <= n; i ++ ){
		cin >> a >> b;
		for(int j = 0 ; j < W; j ++ ){
			if(T[j].size() == 4)
				continue;
			if(dp[i - 1][j][a] == (int)1e9)
				continue;
			ok = true;
			sm = 0;
			pw = 1;
			for(auto x : T[j]){
				if(ok && x >= b){
					sm += b * pw;
					pw *= 13;
					ok = false;
				}
				sm += x * pw;
				pw *= 13;
			}
			if(ok)
				sm += b * pw, pw *= 13;
			cur = pi[sm];
			for(int v1 = 1; v1 <= 9; v1 ++ ){
				for(int v2 = 1; v2 <= 9 ; v2 ++ ){
					dist = dis(a, v1) + dis(v1, v2);
					li = min({a, v1, v2});
					ri = max({a, v1, v2});
					upd(dp[i][new_state(cur, li, ri)][v2], dp[i - 1][j][a] + dist);
				}
			}
		}
	}
	int answ = (int)1e9;
	for(int i = 1; i <= 9; i ++ ){
		answ = min(answ, dp[n][0][i]);
	}
	cout << answ + 2 * n;
	return 0;
}
























void f(vector<int> t, int ls){
	int hsh = 0, pwr = 1;
	for(int i = 0; i < t.size(); i ++ ){
		hsh += t[i] * pwr;
		pwr *= 13;
	}
	id[cnt] = hsh;
	pi[hsh] = cnt;
	T[cnt ++ ] = t;
	if(t.size() == 4)
		return;
	for(int j = ls ; j <= 9; j ++ ){
		t.push_back(j);
		f(t, j);
		t.pop_back();
	}		
}

void init(){
	f({}, 1);
}