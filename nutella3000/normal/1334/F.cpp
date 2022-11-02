#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;
const int max_n = 5e5 + 3;
 
int n, m;
vector<int> a, p, b;
 
struct fenwick{
	vector<int> sum;
 
	fenwick(int n) {
		sum.resize(n);
	}
 
	int f(int x) {
		return x & (x + 1);
	}
 
	int g(int x) {
		return x | (x + 1);
	}
 
 
	void add(int id, int x) {
		while(id < sum.size()) {
			sum[id] += x;
			id = g(id);
		}
		//sum[id] += x;
	}
 
	int get_(int r) {
		int res = 0;
		while(r >= 0) {
			res += sum[r];
			r = f(r) - 1;
		}
		return res;
	}
 
	int get(int l, int r) {
		return get_(r) - get_(l - 1);
		/*int res = 0;
		for(int i = l;i <= r;i++) res += sum[i];
		return res;*/
	}
};
 
fenwick t = fenwick(max_n);


void solve() {
	cin >> n;
	n++;
	a.resize(n + 1); p.resize(n + 1);
	a[0] = 0;
	for(int i = 1;i < n;i++) cin >> a[i];
	for(int i = 1;i < n;i++) cin >> p[i];
 
	a[n] = 1e9 + 1;
	n++;
 
 
	cin >> m;
	m++;
	b.resize(m + 1);
	b[0] = 0;
	for(int i = 1;i < m;i++) cin >> b[i];
	b[m] = 1e9 + 1;
	m++;


 
	map<int, vector<int>> ind;
 
	for(int i = 0;i < n;i++) ind[a[i]].emplace_back(i);
		
	deque<int> sorted;

	for(int i = 0;i < n;i++) {
		t.add(i, p[i]);
		if (p[i] > 0) sorted.emplace_back(i);
	}

	sort(sorted.begin(), sorted.end(), [](int v1, int v2) {return a[v1] < a[v2];});

	vector<int> dp(n, inf);

	dp[0] = 0;

	for(int temp1 = 0;temp1 < m - 1;temp1++) {
		int v = b[temp1];
		int next = b[temp1 + 1];

		while(!sorted.empty() && a[sorted.front()] <= v) {
			int id = sorted.front();
			t.add(id, -p[id]);
			sorted.pop_front();
		}


		vector<int> s;
		for(int i : ind[v]) s.emplace_back(i);
		for(int i : ind[next]) s.emplace_back(i);

		sort(s.begin(), s.end());

		int new_res = inf;
		int last = 0;

		for(int i : s) {
			new_res += t.get(last, i);
			last = i + 1;
			if (a[i] == v) new_res = min(new_res, dp[i]);
			else dp[i] = new_res - p[i];
		}


		/*int new_res = inf;

		for(int i = 0;i < n;i++) {
			if (a[i] == next) dp[i] = new_res;
			new_res += t.get(i, i);
			//if (p[i] < 0 || a[i] > v) new_res += p[i];
			if (a[i] == v) new_res = min(new_res, dp[i]);
		}*/


		/*for(int i : ind[v]) {
			for(int j : ind[next]) {
				if (j > i)
					dp[j] = min(dp[j], dp[i] + t.get(i + 1, j - 1));
			}
		}*/
	}

	if (dp[n - 1] > inf / 2) cout << "NO";
	else {
	cout << "YES" << endl << dp[n - 1];
	}
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);
 
 
   	solve();
}