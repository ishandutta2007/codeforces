#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 3e5 + 7;
int n, ok;

struct pr {
	ll x;
	int id;
} a[N];

ll x, y;
bool work() {
	int tp = 0;
	R(i, n, 1) {
		if(a[i].x * (n - i + 1) >= x) {
			tp = i;
			break;
		}
	}
	
	R(i, tp - 1, 1) {
		if(a[i].x * (tp - i) >= y) {
			cout << "Yes\n";
			if(ok == 0) {
				cout << n - tp + 1 << " " << tp - i << "\n";
				L(t, tp, n) cout << a[t].id << " ";
				cout << "\n";
				L(t, i, tp - 1) cout << a[t].id << " ";
				cout << "\n";	
			}
			else {
				cout << tp - i << " " << n - tp + 1 << "\n";
				L(t, i, tp - 1) cout << a[t].id << " ";
				cout << "\n";
				L(t, tp, n) cout << a[t].id << " ";
				cout << "\n";
			}
			return true;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> x >> y;
	L(i, 1, n) cin >> a[i].x, a[i].id = i;
	sort(a + 1, a + n + 1, [&] (pr a, pr b) {
		return a.x < b.x;
	});
	if(work()) return 0;
	swap(x, y), ok = true;
	if(work()) return 0;
	cout << "No\n";
	return 0;
}