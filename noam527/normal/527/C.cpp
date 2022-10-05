#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int h, w, n, p;
char c;

int main() {
	fast;
	cin >> w >> h >> n;
	set<int> wi, hi;
	multiset<int> disw, dish;
	wi.insert({ 0, w }), hi.insert({ 0, h });
	disw.insert(w), dish.insert(h);
	while (n--) {
		cin >> c >> p;
		if (c == 'H') {
			auto it1 = hi.insert(p).first, it2 = it1, it3 = it1;
			it2--, it3++;
			auto it4 = dish.find(*it3 - *it2);
			dish.erase(it4), dish.insert({ *it1 - *it2, *it3 - *it1 });
		}
		else {
			auto it1 = wi.insert(p).first, it2 = it1, it3 = it1;
			it2--, it3++;
			auto it4 = disw.find(*it3 - *it2);
			disw.erase(it4), disw.insert({ *it1 - *it2, *it3 - *it1 });
		}
		auto temp1 = dish.end(), temp2 = disw.end();
		temp1--, temp2--;
		cout << (ll)*temp1 * (ll)*temp2 << endl;
	}
}