#include <bits/stdc++.h>
#pragma optimize("unroll-loop", "O2")
// Pls don't give me expert
// Back to the origin in 2019...
 
using namespace std;
#define MAXN 4001
// Thank you.
int32_t ans[2000][2000];
struct BIT{
	int32_t bit[MAXN][MAXN];
	void init(){
		for(int i = 0; i < MAXN; i++){
			fill(bit[i] + 0, bit[i] + MAXN, 0);
		}
	}
	
	void upd(int x, int y, int v){
		for(int i = x; i < MAXN; i += i & -i){
			for(int j = y; j < MAXN; j += j & -j){
				bit[i][j] += v;
			}
		}
	}
	
	int qry(int x, int y){
		int res = 0;
		for(int i = x; i > 0; i -= i & -i){
			for(int j = y; j > 0; j -= j & -j){
				res += bit[i][j];
			}
		}
		return res;
	}
	
	int qry(int r1, int r2, int c1, int c2){
		if(r1 < 0) r1 = 0; if(r2 >= MAXN) r2 = MAXN - 1;
		if(c1 < 0) c1 = 0; if(c2 >= MAXN) c2 = MAXN - 1;
		return qry(r2, c2) - qry(r2, c1 - 1) - qry(r1 - 1, c2) + qry(r1 - 1, c1 - 1);
	}
	
	int qry_all(){
		return qry(MAXN - 1, MAXN - 1);
	}
} bit[1];
 
int A[2001][2001];
void solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> A[i][j];
		}
	}
	vector<pair<pair<int, int>, int>> vp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			vp.push_back({{i + j + 1, n + i - j}, A[i][j]});
		}
	}
	sort(vp.begin(), vp.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
		return a.second > b.second;
	});
	/*
	for(auto i : vp){
		cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
	}*/
	bit[0].init();
	for(int i = 0; i < n * n; i++){
		int x = vp[i].first.first, y = vp[i].first.second, id = vp[i].second;
		int q0 = bit[0].qry_all() - bit[0].qry(x - k, x + k, y - k, y + k);
		int lose = q0 == 0;
		ans[(x + y - 1 - n) / 2][(x - y - 1 + n) / 2] = lose;
		bit[0].upd(x, y, 1 - (!lose));
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << (ans[i][j] ? 'M' : 'G');
		}
		cout << endl;
	}
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}