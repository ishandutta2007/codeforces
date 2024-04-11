#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <stack>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const ll md = 1e9 + 7, sz = 1e5;
int n;
ll x, y;
pii sh[sz];
pair<int, pair<bool, int>> t[2*sz];//time, close?
int mytv[sz];
priority_queue<int> tvs;//check

int main() {
	fast;
	cin >> n >> x >> y;
	foru(i, 0, n) {
		cin >> sh[i].first >> sh[i].second;
		t[2 * i] = mp(sh[i].first, mp(false, i));
		t[2 * i + 1] = mp(sh[i].second, mp(true, i));
	}
	//sort(sh, sh + n);
	sort(t, t + 2 * n);
	ll tot = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (t[i].second.first) { //close
			tvs.push(t[i].first);
			tot += y * (sh[t[i].second.second].second - sh[t[i].second.second].first);
		}
		else {
			if (!tvs.empty()) {
				ll opt1 = tvs.top(); tvs.pop();
				if (x >= y*(t[i].first - opt1)) {
					tot += y * (t[i].first - opt1);
				}
				else {
					tot += x;
				}
			}
			else tot += x;
		}
		tot %= md;
	}
	cout << tot << endl;
	return 0;
}