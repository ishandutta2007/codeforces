#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n, m, counter,minc;

vector<bool> used;
vector<int> v[1000000];
vector<int> c;
int dfs(int x) {
	used[x] = false;
	if (v[x].size() == 1 && x != 1){
		return 1;
	}
	else {
		int counter = 1;
		for (int i = 0; i < v[x].size(); i++) {
			if (used[v[x][i]]) {
				counter += dfs(v[x][i]);
				if (c[x] == c[v[x][i]]) {
					counter--;
				}
			}
		}
		return counter;
	}
}
int main()
{
	cin >> n;
	c.resize(n + 1);
	used.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		int l;
		cin >> l;
		v[i].push_back(l);
		v[l].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	fill(used.begin(), used.end(),true);
	cout << dfs(1);
}