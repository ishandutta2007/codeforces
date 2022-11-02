#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 600100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int p[N];
int d[N];
bool v[N];

void init(void) {
	rep(i, N) {
		p[i] = i;
		d[i] = 1;
		v[i] = false;
	}
	return;
}

int pa(int x) {
	if (p[x] == x)return x;
	else return p[x] = pa(p[x]);
}


void uni(int x, int y) {
	int px = pa(x);
	int py = pa(y);
	if (px == py)return;
	if (d[px] < d[py]) {
		p[px] = py;
		d[py] = max(d[py], d[px] + 1);
		v[py] = (v[px] | v[py]);
	}
	else {
		p[py] = px;
		d[px] = max(d[px], d[py] + 1);
		v[px] = (v[px] | v[py]);
	}
	return;
}

bool jud(int x, int y) {
	int px = pa(x);
	int py = pa(y);
	if (px == py)return true;
	else return false;
}



int main() {
	init();
	int n, m;
	int x, y, k;
	ll s = (ll)1;
	vi ans;
	cin >> n >> m;
	rep(i, n) {
		cin >> k;
		if (k == 1) {
			cin >> x;
			x--;
			x = pa(x);
			if (!v[x]) {
				ans.pb(i + 1);
				v[x] = true;
			}
		}
		else {
			cin >> x >> y;
			x--;
			y--;
			x = pa(x);
			y = pa(y);
			if ((!(v[x] && v[y])) && (!(jud(x, y)))) {
				ans.pb(i + 1);
				uni(x, y);
			}
		}
	}
	x = ans.size();
	rep(i, x)s = (s*((ll)2)) % MOD;
	cout << s << " " << x << endl;
	rep(i, x - 1)cout << ans[i] << " ";
	cout << ans[x - 1] << endl;
	return 0;
}