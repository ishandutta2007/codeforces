#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ll> vi;

const int sz = 1e6 + 5;
int n;
int a[sz];
vector<pll> hl;

int main() {
	fast;
	hl.pb({ 0,0 });
	cin >> n;
	ll cursum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cursum += a[i];
		pll cand = { i,cursum };
		if (hl.size() < 2)hl.push_back(cand);
		else {
			while (hl.size() >= 2) {
				pll b1 = hl.back(), b2 = hl[hl.size() - 2];
				pll d1 = { cand.ff - b1.ff,cand.ss - b1.ss }, d2 = { b1.ff - b2.ff,b1.ss - b2.ss };
				if (d1.ff * d2.ss - d2.ff * d1.ss <= 0)break;
				else hl.pop_back();
			}
			hl.push_back(cand);
		}
	}
	int idx = 1;
	for (int i = 1; i < hl.size(); i++) {
		int amt = 0;
		while (idx <= hl[i].ff) {
			idx++;
			amt++;
		}
		for (int j = hl[i - 1].ff + 1; j <= hl[i].ff; j++)
			cout << fixed << setprecision(10) << (ld)(hl[i].ss - hl[i - 1].ss) / amt << '\n';
	}
	return 0;
}