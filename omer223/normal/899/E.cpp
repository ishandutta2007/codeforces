
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <set>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef pair<pii, int> comp;
ll modpow(ll a, ll b, ll md) { ll res = 1; a %= md; for (; b; b >>= 1) { if (b & 1)res = res * a%md; a = a * a%md; }return res; }

int n;

int main() {
	fast;
	set<comp> seg;//pos,amt,num
	set<comp, greater<comp>> segmax; //amt, pos, num
	cin >> n;
	int prv = -1, amt = 0, tmp, crpos=0;
	foru(i, 0, n) {
		cin >> tmp;
		if (prv == -1 || prv==tmp) amt++;	
		else {
			seg.insert(mp(mp(crpos, amt), prv));
			segmax.insert(mp(mp(amt, -crpos), prv));
			crpos += amt;
			amt = 1;
		}
		prv = tmp;
	}
	if (amt) {
		seg.insert(mp(mp(crpos, amt), prv));
		segmax.insert(mp(mp(amt, -crpos), prv));
	}
	int moves = 0;
	while (!seg.empty()) {
		moves++;
		comp x = *segmax.begin();
		segmax.erase(x);
		int pos = -x.first.second, amt = x.first.first, val = x.second;
		comp y = mp(mp(pos, amt), val);
		auto iter = seg.find(y), iterb = iter, itera = iter;
		iterb--;
		itera++;
		if (iterb != seg.end() && itera != seg.end() && iterb->second == itera->second) {
			comp pp = *iterb, qq = *itera; seg.erase(pp); seg.erase(qq);
			seg.insert(mp(mp(pp.first.first, pp.first.second + qq.first.second), pp.second));
			segmax.erase({ {qq.first.second,-qq.first.first}, qq.second });
			segmax.erase({ {pp.first.second,-pp.first.first},pp.second });
			segmax.insert({ {pp.first.second + qq.first.second,-pp.first.first}, pp.second });
		}
		seg.erase(y);
	}
	cout << moves << endl;
	return 0;
}