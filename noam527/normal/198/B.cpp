#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n, k, v;
	vector<int> dis(200002, -1);
	string s[2];
	cin >> n >> k >> s[0] >> s[1];
	queue<int> q;
	q.push(0), dis[0] = 0;
	while (!q.empty()) {
		v = q.front(), q.pop();
		if (v % n + 1 >= n || v % n + k >= n) {
			cout << "YES" << endl;
			return 0;
		}
		if (dis[v + 1] == -1 && s[v / n][v % n + 1] != 'X') dis[v + 1] = dis[v] + 1, q.push(v + 1);
		if (v % n > 0 && dis[v - 1] == -1 && s[v / n][v % n - 1] != 'X' && (v - 1) % n >= dis[v] + 1) dis[v - 1] = dis[v] + 1, q.push(v - 1);
		int x = (v + n) % (2 * n) + k;
		if (dis[x] == -1 && s[x / n][x % n] != 'X') dis[x] = dis[v] + 1, q.push(x);
	}
	cout << "NO" << endl;
	return 0;
}