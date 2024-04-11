#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;

const int N = 1e6 + 7; 
int n, m, tp;
ll x[N], p[N];
pair < ll, ll > arr[N];
void Main() {
	cin >> n >> m;
	L(i, 1, n) {
		cin >> p[i];
	}
	L(i, 1, m) {
		cin >> x[i], x[i] *= 2;
	}
	x[0] = -1e10, x[m + 1] = 1e10;
	sort(x + 1, x + m + 1);
	tp = 0;
	L(i, 1, n) {
		int P = (i - 1) * 200;
		int lt = lower_bound(x + 1, x + m + 1, P) - x;
		ll dis = min(abs(x[lt] - P), abs(x[lt - 1] - P));
//		cout << "dis = " << dis << '\n';
		if(dis > 0) {
			ll dl = P - dis + 1;
			ll dr = P + dis - 1;
			++tp, arr[tp] = make_pair(dl, p[i]);
			++tp, arr[tp] = make_pair(dr + 1, -p[i]);
		} 
	}
	sort(arr + 1, arr + tp + 1);
	ll sum = 0, ns = 0;
	L(i, 1, tp) sum += arr[i].second, ns = max(ns, sum); //, cout << arr[i].first << " : " << sum << '\n';
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Main();
	return 0; 
}