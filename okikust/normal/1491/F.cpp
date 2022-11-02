#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
	int n;
	int left, right, mid;
	int x, y, z;
	vector<int>ans;
	int sz;
	bool used[N];
	int cur = 2;
	int t;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		cur = 2;
		ans.clear();
		while (true) {
			cout << "? " << cur - 1 << " " << 1 << endl;
			cout.flush();
			rep2(i, 1, cur - 2)cout << i << " ";
			cout << cur - 1 << endl;
			cout.flush();
			cout << cur << endl;
			cout.flush();
			cin >> z;
			if (z != 0)break;
			cur++;
		}
		left = 0;
		right = cur - 1;
		while (left + 1 < right) {
			mid = (left + right) / 2;
			cout << "? " << mid << " " << 1 << endl;
			cout.flush();
			rep2(i, 1, mid - 1)cout << i << " ";
			cout << mid << endl;
			cout.flush();
			cout << cur << endl;
			cout.flush();
			cin >> z;
			if (z != 0)right = mid;
			else left = mid;
		}
		rep2(i, 1, cur)used[i] = false;
		used[right] = true;
		used[cur] = true;
		rep2(i, cur + 1, n) {
			cout << "? " << 1 << " " << 1 << endl;
			cout.flush();
			cout << cur << endl;
			cout.flush();
			cout << i << endl;
			cout.flush();
			cin >> z;
			if (z != 0)used[i] = true;
			else used[i] = false;
		}
		rep2(i, 1, n)if (!used[i])ans.pb(i);
		sz = ans.size();
		cout << "! " << sz;
		rep(i, sz)cout << " " << ans[i];
		cout << endl;
		cout.flush();
	}
	return 0;
}