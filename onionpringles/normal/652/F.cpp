#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <functional>
#include <complex>
#include <random>
#include <time.h>
#include <tuple>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)
#define print(x) printf("%d\n", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 300000;

int s[N];

vector<int> up;
vector<int> down;

vector<int> endpos;

int ans[N];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t;
	int n, m; nii(n, m); scanf("%I64d", &t); int cur = 0;
	F(i, n) {
		ni(s[i]); char d; scanf(" %c", &d);
		if (d == 'R') up.push_back(i);
		else down.push_back(i);
		if (i == 0) {
			if (d == 'R') cur = 1;
			else cur = -1;
		}
	}
	if (up.empty()) {
		F(i, n) {
			ll tm = s[i] - t;
			tm %= m; if (tm <= 0) tm += m;
			printf("%d ", (int)tm);
		}
		return 0;
	}
	else if (down.empty()) {
		F(i, n) {
			int tm = (s[i] + t) % m;
			if (!tm) tm = m;
			printf("%d ", tm);
		}
		return 0;
	}
	int start = 0;
	for (auto &x : up) {
		start = x;
		ll tm = t + s[x];
		tm %= m;
		endpos.push_back(tm);
	}
	for (auto &y : down) {
		ll tm = -t + s[y];
		tm %= m;
		if (tm < 0) tm += m;
		endpos.push_back(tm);
	}
	sort(endpos.begin(), endpos.end());
	ll q = t / ((ll)m*n);
	ll r = t % ((ll)m*n);
	int u = up.size();
	int l = down.size();
	ll K = (ll)u*l;
	
	for (auto &x : up) {
		if (x == start) continue;
		if (s[x] > s[start]) s[x] -= m;
	}
	for (auto &x : down) {
		if (s[x] < s[start]) s[x] += m;
	}
	sort(up.begin(), up.end(), [&](int a, int b) {
		return s[a] > s[b];
	});
	sort(down.begin(), down.end(), [&](int a, int b) {
		return s[a] < s[b];
	});
	ll pos;
	ll low = 0; ll high = 4 * K;
	while (low != high) {
		ll mid = (low + high) / 2;
		ll ln = mid / 2;
		ll un = mid - mid / 2;
		ll cc = s[down[ln%l]] - s[up[un%u]] + (un / u)*m + (ln / l)*m;
		if (cc >= 2 * r) high = mid;
		else low = mid + 1;
	}
	int highflag = 0;
	if (high % 2) {
		highflag = 1;
		ll ln = high / 2;
		pos = s[down[ln%l]] + (ln / l)*m - r;
	}
	else {
		ll un = high / 2;
		pos = r + s[up[un%u]] - (un / u)*m;
	}
	pos %= m;
	if (pos < 0) pos += m;
	int startind = -1;
	int cnt = 0;
	F(i, n) {
		if (endpos[i] == pos) {
			startind = i;
			cnt++;
		}
	}
	if (cnt == 2 && !highflag) {
		startind--;
	}
	int j = startind;
	vector<int> srt(n);
	F(i, n) {
		srt[i] = i;
		if (i == start)continue;
		while (s[i] < s[start])s[i] += m;
	}
	sort(srt.begin(), srt.end(), [&](int a, int b) {return s[a] < s[b]; });
	F(i, n) {
		ans[srt[i]] = endpos[j++];
		if (j == n) j = 0;
	}

	F(i, n) {
		printf("%d ", (ans[i]) ? ans[i] : m);
	}



	return 0;
}