#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>
#include <numeric> 
using namespace std;

#define int long long
#define pb push_back

const int N = 5e5 + 10;
int p[N], h[N];
vector<int> sz(N, 1);

int find_set(int a) {
	if (a == p[a]) {
		return a;
	}
	else {
		return p[a] = find_set(p[a]);
	}
}

void union_set(int i, int j) {
	int a = find_set(i);
	int b = find_set(j);
	if (a != b) {
		if (h[a] < h[b]) {
			swap(a, b);
		}
		p[b] = a;
		if (h[a] == h[b]) {
			h[a]++;
		}
		sz[a] += sz[b];
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	int n, m;
	cin >> n >> m;
	while (m--) {
		int k;
		cin >> k;
		vector<int> v(k);
		for (int i = 0; i < k; i++) {
			cin >> v[i];
			v[i]--;
		}
		for (int i = 0; i < k - 1; i++) {
			union_set(v[i], v[i + 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << sz[find_set(i)] << " ";
	}
}