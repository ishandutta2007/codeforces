#include <bits/stdc++.h>

using namespace std;

int A[600002];
bool ex[300002];
int ans[300002][2];

map<int, vector<int>> M;
int B = 600; 
struct Query{
	int l, r, id;
	bool operator< (const Query& o) const{
		return l / B < o.l / B || l / B == o.l / B && (l / B % 2 ? r < o.r : r > o.r); 
	}
};

vector<Query> Q;

int L = 0, R = -1;
int cnt[300001];
int res = 0;
int work = 0;
inline int qry(int l, int r){
	while(L < l){
		res -= cnt[A[L]] == 1;
		cnt[A[L]]--;
		L++;
		work++;
	}
	while(L > l){
		res += cnt[A[L - 1]] == 0;
		cnt[A[L - 1]]++;
		L--;
		work++;
	}
	while(R > r){
		res -= cnt[A[R]] == 1;
		cnt[A[R]]--;
		R--;
		work++;
	}
	while(R < r){
		res += cnt[A[R + 1]] == 0;
		cnt[A[R + 1]]++;
		R++;
		work++;
	}
	return res;
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		A[i] = n - i;
		M[A[i]].push_back(i);
	}
	for(int i = n; i < n + m; i++){
		cin >> A[i];
		M[A[i]].push_back(i);
		ex[A[i]] = true;
	}
	for(int i = 1; i <= n; i++){
		M[i].push_back(n + m);
	}
	for(int i = 1; i <= n; i++){
		if(ex[i]){
			ans[i][0] = 1;
		}else{
			ans[i][0] = i;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (int) M[i].size() - 1; j++){
			Q.push_back({M[i][j] + 1, M[i][j + 1] - 1, i});
		}
	}
	sort(Q.begin(), Q.end()); 
	for(int i = 0; i < (int) Q.size(); i++){
		ans[Q[i].id][1] = max(ans[Q[i].id][1], qry(Q[i].l, Q[i].r));
	}
	
	// cout << work << endl;
	for(int i = 1; i <= n; i++){
		cout << ans[i][0] << ' ' << ans[i][1] + 1 << endl;
	}
	cout << endl;
}