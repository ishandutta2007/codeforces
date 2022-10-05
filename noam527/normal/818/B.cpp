#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
typedef long long ll;
typedef double db;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(n, -1);
	set<int> free;
	for (int i = 0; i < n; i++) free.insert(i + 1);
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < m - 1; i++) {
		if (b[a[i] - 1] != -1 && b[a[i] - 1] != (a[i + 1] - a[i] + n - 1) % n + 1) {
			cout << -1 << endl;
			return 0;
		}
		b[a[i] - 1] = (a[i + 1] - a[i] + n - 1) % n + 1, free.erase((a[i + 1] - a[i] + n - 1) % n + 1);
	}
	for (int i = 0; i < b.size(); i++)
		if (b[i] == -1)
			b[i] = *free.begin(), free.erase(free.begin());
	for (int i = 0; i < b.size(); i++) for (int j = i + 1; j < b.size(); j++)
		if (b[i] == b[j]) {
			cout << -1 << endl;
			return 0;
		}
	for (int i = 0; i < b.size(); i++) cout << b[i] << " "; cout << endl;
}