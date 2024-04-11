#include <iostream>
#include <map>

using namespace std;

int n;
int a[202020];
int b[202020];
map<int,int> m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		b[x] = i;
	}
	int u = 0;
	for (int i = 1; i <= n; i++) {
		int d = a[i]-b[i];
		if (d < 0) d += n;
		m[d]++;
		u = max(u,m[d]);
	}
	cout << u << "\n";
}