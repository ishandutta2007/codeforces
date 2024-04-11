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

const int sz = 2e5;
int n, k;
ll a[sz], used[sz];

ll calc(ll x, int pieces) {
	ll small = x / pieces, laamt = x % pieces, smamt = pieces - laamt;
	return (small * small * smamt + (small + 1) * (small + 1) * laamt);
}

int main() {
	fast;
	ll now = 0;
	cin >> n >> k; k -= n;
	priority_queue<pll> pq;
	foru(i, 0, n) {
		cin >> a[i]; now += a[i] * a[i];
		pq.push({ calc(a[i],1) - calc(a[i],2), i });
	}
	foru(i, 0, k) {
		pll ii = pq.top(); pq.pop();
		now -= ii.ff;
		used[ii.ss]++;
		pq.push({calc(a[ii.ss], used[ii.ss] + 1) - calc(a[ii.ss],used[ii.ss] + 2),ii.ss });
	}
	cout << now;
	return 0;
}