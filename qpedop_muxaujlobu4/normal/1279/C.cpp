#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<tuple>
#include<string>
using namespace std;
int a[100001];
bool visited[100001];
int b[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n,m;
		cin >> n>>m;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			visited[i] = false;
		}
		for (int i = 1; i <= m; ++i) {
			cin >> b[i];
		}
		int dis = 1;
		long long s = 0;
		for (int i = 1; i <= m; ++i) {
			if (visited[b[i]])s += 1;
			else {
				int id = dis;
				for (; !visited[b[i]]; ++id) {
					visited[a[id]] = true;
				}
				dis = id;
				s += (id - i) * 2 - 1;
			}
		}
		cout << s << "\n";
	}
	return 0;
}