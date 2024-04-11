#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
#define mod 1000000007
using namespace std;
vector<vector<int>> A(26), B(26);

int L[200010];
#define N 200007
int bit[200010];
int add(int p, int v){
	p++;
	while(p < N) bit[p] += v, p += p & -p;
}

int sum(int r){
	int res = 0;
	r++;
	while(r) res += bit[r], r -= r & -r;
	return res;
}

int32_t main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int idx = 0;
	for(auto i : t){
		A[i - 'a'].push_back(idx++);
	}
	
	int pos[26] = {};
	fill(pos, pos + 26, 0);
	for(int i = 0; i < n; i++){
		int c = s[i] - 'a';
		L[i] = A[c][pos[c]++];
	}
	
	int ans = 0;
	vector<pair<int, int>> M;
	for(int i = 0; i < n; i++){
		M.push_back({L[i], i});
	}
	sort(M.begin(), M.end());
	for(int i = 0; i < n; i++){
		add(i, 1);
	}
	for(int i = 0; i < n; i++){
		ans += sum(M[i].second - 1);
		add(M[i].second, -1);
	}
	cout << ans << endl;
}