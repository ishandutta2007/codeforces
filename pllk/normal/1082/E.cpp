#include <iostream>

using namespace std;

#define INF 999999999

int n, c;
int s[505050];
int z[505050];
int a[505050];
int r[505050];

int main() {
	cin >> n >> c;
	int u = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= 500000; i++) z[i] = -1;
	for (int i = n; i >= 1; i--) {
		r[i] = r[i+1]+(a[i]==c);
	}
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		s[x]++;
		z[x] = max(z[x],s[c]-s[x]);
		if (x != c) u = max(u,s[x]+z[x]+r[i+1]+1);
	}
	cout << max(u,s[c]) << "\n";
}