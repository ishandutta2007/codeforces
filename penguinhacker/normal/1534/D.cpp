#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2000;
int n, d[mxN];
set<ar<int, 2>> ans;
vector<int> to;
bool vis[mxN];

void ins(int a, int b) {
	if (a>b)
		swap(a, b);
	ans.insert({a, b});
}

void qry(int u) {
	cout << "? " << u+1 << endl;
	for (int i=0; i<n; ++i) {
		cin >> d[i];
		if (d[i]==1)
			ins(u, i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	qry(0);
	vector<int> p[2];
	for (int i=0; i<n; ++i)
		if (d[i])
			p[d[i]%2].push_back(i);
	if (p[1].size()<p[0].size())
		swap(p[0], p[1]);
	for (int i : p[0])
		qry(i);
	assert(ans.size()==n-1);
	cout << "!" << endl;
	for (ar<int, 2> a : ans)
		cout << a[0]+1 << " " << a[1]+1 << endl;
	return 0;
}