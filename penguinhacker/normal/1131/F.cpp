#include <bits/stdc++.h>
using namespace std;

int par[150001], r[150001];
vector<int> elements[150001];
//dsu
void make_set(int u) {
	par[u]=u;
	r[u]=0;
	elements[u].push_back(u);
}
int find_set(int u) {
	if (par[u]==u)
		return u;
	return par[u]=find_set(par[u]);
}
void merge_set(int a, int b) {
	a=find_set(a);
	b=find_set(b);
	if (r[a]<r[b])
		swap(a, b);
	par[b]=a;
	if (r[a]==r[b])
		r[a]++;
	for (int i:elements[b])
		elements[a].push_back(i);
	elements[b].clear();
}

int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		make_set(i);
	for (int i=0, a, b; i<n-1; ++i) {
		cin >> a >> b;
		merge_set(a, b);
	}
	for (int i:elements[find_set(1)])
		cout << i << ' ';
	return 0;
}