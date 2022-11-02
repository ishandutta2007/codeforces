#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, k;

vector<pair<string, int>> inst, fininst;

inline void mypb(const string& str, int rep) {
	if (rep > 0)inst.pb({ str,rep });
}

void pushHam() {//n,m<=2
	string down = "", tmp = "";
	int cur = 1;
	while (cur <= n) {
		if (cur & 1)mypb("R", m - 1);
		else mypb("L", m - 1);
		if (cur != n)mypb("D", 1);
		cur++;
	}
	cur = n;
	while (cur > 1) {
		if (!(cur & 1)) mypb("UDR", m - 1);
		else mypb("UDL", m - 1);
		mypb("U", 1);
		cur--;
	}
	mypb("L", m - 1);
}

int main() {
	fast;
	cin >> n >> m >> k;
	if (4 * m*n - 2 * m - 2 * n < k) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	pushHam();
	int cur = 0;
	for (auto i : inst) {
		int amt = i.ss*i.ff.length();
		if (cur + amt <= k) {
			fininst.pb(i);
			cur += amt;
			if (cur == k)break;
		}
		else {
			int len = i.ff.length();
			int rem = k - cur;
			int fulls = rem / len;
			if(fulls)fininst.pb({ i.ff,fulls });
			if(rem%len!=0)fininst.pb({ i.ff.substr(0,rem%len),1 });
			break;
		}
	}
	cout << fininst.size() << '\n';
	for (auto x : fininst)cout << x.ss << ' ' << x.ff << '\n';
	return 0;
}