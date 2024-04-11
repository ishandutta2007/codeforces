#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forq(i, q, n) for (int i = (int)q; i < (int)n; ++i)
#define mk make_pair
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define X first
#define Y second
#define TASK ""

const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;
const int MAXN = 5 * (int)1e6 + 7;
const double EPS = (double)1e-7;

vector <ll> pf (vector <pair <char, ll> > s) {
	vector <ll> pi(s.size());
	for (ll i = 1; i < s.size(); ++i) {
		ll j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j]) {
			j++;
		}
		pi[i] = j;
	}
	return pi;
}

vector <pair <char, ll> > a, ob, b;
ll ans;

void check(int x) {
	if (x == ob.size() - 1) {
		return;
	}
	pair <char, ll> p = ob[x + 1];
	x -= b.size() - 2;
	pair <char, ll> r = ob[x];
	if (p.X == b[b.size() - 1].X && r.X == b[0].X && p.Y >= b[b.size() - 1].Y && r.Y >= b[0].Y) {
		ans++;
	}
}

int main() {
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, m;
	cin >> n >> m;
	vector <pair <char, ll> > a1(n + 1);
	forn(i, n) {
		scanf("%I64d-%c", &a1[i].Y, &a1[i].X);
	}
	a1[n].X = '`';
	vector <pair <char, ll> > b1(m + 1);
	forn(i, m) {
		scanf("%I64d-%c", &b1[i].Y, &b1[i].X);
	}
	b1[m].X = '`';
	forn(i, m) {
		if (b1[i].X != b1[i + 1].X) {
			b.psh(b1[i]);
			if (b.size() > 1) {
				ob.psh(b1[i]);
			}
		}
		else {
			b1[i + 1].Y += b1[i].Y;
		}
	}
	if (ob.size() > 1) {
		ob.resize(ob.size() - 1);
	}
	ob.psh(mk('`', -INF));
	forn(i, n) {
		if (a1[i].X != a1[i + 1].X) {
			a.psh(a1[i]);
			ob.psh(a1[i]);
		}
		else {
			a1[i + 1].Y += a1[i].Y;
		}
	}
	if (b.size() == 1) {
		forn(i, a.size()) {
			if (a[i].X == b[0].X) {
				ans += max(0ll, a[i].Y - b[0].Y + 1);
			}
		}
		cout << ans;
		return 0;
	}
	vector <ll> pr = pf(ob);
	forn(i, pr.size()) {
		if (pr[i] == b.size() - 2) {
			check(i);
		}
	}
	cout << ans;
	return 0;
}