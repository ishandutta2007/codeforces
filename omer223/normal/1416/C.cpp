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

const int sz = 4e5;
ll a[sz], n;
ll curinv[32], flipinv[32];

void foo(vector<int> v, int b) {
	if (b < 0||v.empty())return;
	vector<int> zvec, ovec;
	int z = 0, o = 0;
	for (int k : v) {
		if ((k >> b) & 1) {
			o++;
			flipinv[b] += z;
			ovec.pb(k);
		}
		else {
			z++;
			curinv[b] += o;
			zvec.pb(k);
		}
	}
	foo(zvec, b - 1);
	foo(ovec, b - 1);
}

int main() {
	fast;
	cin >> n;
	vector<int> v;
	foru(i, 0, n) {
		cin >> a[i];
		v.pb(a[i]);
	}
	foo(v, 31);
	ll mynum = 0, totinv = 0;
	foru(b, 0, 32) {
		if (curinv[b] <= flipinv[b])totinv += curinv[b];
		else {
			totinv += flipinv[b];
			mynum |= (1 << b);
		}
	}
	cout << totinv << " " << mynum << endl;
	return 0;
}