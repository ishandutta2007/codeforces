#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define N 100000
#define Z 500

int n, q;
int a[N+10];
vector<array<int,3>> v, u;
int z[2*N+10];

void lol() {
	for (auto x : v) {
		if (x[2] == 0) {
			for (int i = x[0]; i <= x[1]; i++) {
				z[N+i] = 0;
			}
		} else {
			for (int i = x[0]; i <= x[1]; i++) {
				z[N-i] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (z[N+a[i]]) a[i] = -a[i];
	}
	v.clear();
	v.push_back({-N,N,0});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	lol();
	for (int k = 1; k <= q; k++) {
		char s;
		int x;
		cin >> s >> x;
		u.clear();
		for (int i = 0; i < v.size(); i++) {
			if (s == '>') {
				if (v[i][1] <= x) continue;
				if (v[i][0] > x) {
					swap(v[i][0],v[i][1]);
					v[i][0] = -v[i][0];
					v[i][1] = -v[i][1];
					v[i][2] = 1-v[i][2];
				} else {
					u.push_back({-v[i][1],-(x+1),1-v[i][2]});
					v[i][1] = x;
				}
			} else {
				if (v[i][0] >= x) continue;
				if (v[i][1] < x) {
					swap(v[i][0],v[i][1]);
					v[i][0] = -v[i][0];
					v[i][1] = -v[i][1];
					v[i][2] = 1-v[i][2];
				} else {
					u.push_back({-(x-1),-v[i][0],1-v[i][2]});
					v[i][0] = x;
				}
			}
		}
		for (auto x : u) v.push_back(x);
		if (k%Z == 0) lol();
	}
	lol();
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << "\n";
}