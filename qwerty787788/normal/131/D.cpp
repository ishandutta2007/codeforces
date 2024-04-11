#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long n;
//
vector <int> a[3001];
int was[3001];
int len[3001];
vector <int> w;
bool out = false;
//
void dfs(int x, int last) {
	was[x] = 1;
	w.push_back(x);
	if (!out) {
	for (int i = 0; i < a[x].size(); i++)
		if (last != a[x][i])
			if (was[a[x][i]] == 0) {
				if (!out)
				dfs(a[x][i], x);
			} else {
				if (!out) {
				 while (w[w.size() - 1] != a[x][i]) {
					len[w[w.size()-1]] = 1;
					w.pop_back();
				}
				 len[w[w.size()-1]] = 1;
				 out = true;
				 return;
				}
			}
	}
	if (!out) w.pop_back();
}
//
void dfs2(int x, int l) {
	if ((len[x] > l) || (len[x] == 0)) len[x] = l;
	for (int i = 0; i < a[x].size(); i++)
		if ((len[a[x][i]] > l + 1) || (len[a[x][i]] == 0)) dfs2(a[x][i], l+1);
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	int x, y;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	//
	dfs(1, -1);
	for (int i = 1; i <= n; i++)
		was[i] = 0;
	for (int i = 1; i <= n; i++)
		if (len[i] == 1) dfs2(i, 1);
	//
	for (int i = 1; i <= n; i++)
		cout << len[i]-1 << " ";
	cout << endl;
	//
	return 0;
}