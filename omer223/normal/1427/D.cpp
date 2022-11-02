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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 52;
int n;
vector<int> a;
vector<pair<pii, pii>> cards;

void initComp() {
	cards.clear();
	int f = a[0], l = a[0];
	foru(i, 1, n) {
		if (a[i] - a[i - 1] == 1)l = a[i];
		else {
			cards.pb({ {f,l}, {i - (l - f + 1),i - 1} });
			f = a[i];
			l = a[i];
		}
	}
	cards.pb({ {f,l },{n - (l - f + 1),n - 1} });
}

void doOperOnArr(vector<int> oper) {
	vector<vector<int>> groups;
	int operSize = oper.size(), ind = 0;
	for (int i = 0; i < operSize; i++) {
		int cnt = 0;
		vector<int> g;
		while (cnt < oper[i]) {
			g.pb(a[ind++]);
			cnt++;
		}
		groups.pb(g);
	}
	reverse(groups.begin(), groups.end());
	a.clear();
	for (vector<int> vv : groups) {
		for (int x : vv)a.pb(x);
	}
}


int main() {
	fast;
	int tmp;
	cin >> n;
	foru(i, 0, n) {
		cin >> tmp;
		a.pb(tmp);
	}
	vector<vector<int>> opers;
	foru(i, 0, n) {
		initComp();
		if (cards.size() == 1)break;
		int compSize = cards.size(), invbig = -1, invsmall = -1;
		foru(j, 0, compSize) {
			foru(k, j + 1, compSize) {
				if (cards[k].first.second + 1 == cards[j].first.first) {
					invbig = j;
					invsmall = k;
					break;
				}
			}
			if (invbig != -1)break;
		}
		vector<int> oper;
		if (cards[invbig].second.first != 0)oper.pb(cards[invbig].second.first);
		oper.pb(cards[invsmall].second.first - cards[invbig].second.first);
		oper.pb(cards[invsmall].second.second - cards[invsmall].second.first + 1);
		if (cards[invsmall].second.second != n - 1)oper.pb(n - 1 - cards[invsmall].second.second);
		doOperOnArr(oper);
		opers.pb(oper);
	}
	cout << opers.size() << '\n';
	for (vector<int> v : opers) {
		cout << v.size() << ' ';
		for (int x : v)cout << x << ' ';
		cout << '\n';
	}
	return 0;
}