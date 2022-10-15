#include <iostream>
#include <vector>

using namespace std;

int n;
pair<int,int> v[101010];
int d[101010];
int r[101010];

int main() {
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = {a,b};
		d[a]++; d[b]++;
		r[i] = -1;
	}
	int x = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] >= 3) x = i;
	}
	int c = 0;
	for (int i = 1; i <= n-1; i++) {
		if (v[i].first == x || v[i].second == x) {
			r[i] = c++;
			if (c == 3) break;
		}
	}
	for (int i = 1; i <= n-1; i++) {
		if (r[i] == -1) r[i] = c++;
	}
	for (int i = 1; i <= n-1; i++) {
		cout << r[i] << "\n";
	}
}