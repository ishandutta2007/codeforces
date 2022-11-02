#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n, m, counter,minc;

vector<bool> used;
vector<int> v[1000000];
vector<int> c;
void dfs(int x) {
	used[x] = false;
	counter--;
	if (c[x] < minc) {
		minc = c[x];
	}
	for (int i = 0; i < v[x].size(); i++) {
		if (used[v[x][i]]) {
			dfs(v[x][i]);
		}
	}
}
int main()
{
	cin >> n >> m;
	c.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		v[l].push_back(r);
		v[r].push_back(l);
	}
	used.resize(n + 1);
	fill(used.begin(), used.end(), true);
	long long sum=0;
	int vc = 1;
	counter = n;
	while (counter > 0 && vc <= n) {
		if (used[vc]) {
			minc = INT_MAX;
			dfs(vc);
			sum += minc;
		}
		vc++;
	}
	cout << sum;
}