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
#include <queue>
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int sz = 3e5;
ll a[sz], n, k;

int main() {
	fast;
	cin >> n >> k;
	foru(i, 0, n)cin >> a[i];
	ll tp = 1, cnt = 0, times=0;
	while (abs(tp) <= 1e14) {
		map<ll, ll> pre;
		ll cur = 0;
		pre[cur]++;
		foru(i, 0, n) {
			cur += a[i];
			pre[cur]++;
			if (pre.find(cur - tp) != pre.end())cnt += pre[cur - tp];
		}
		tp *= k;
		times++;
		if (times >= 1 && k == 1 || times>=2&&k==-1)break;
	}
	cout << cnt << endl;
	return 0;
}