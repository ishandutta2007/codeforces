#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int st[64] = {1ll, 2ll, 3ll, 6ll, 11ll, 22ll, 43ll, 86ll, 171ll, 342ll, 683ll, 1366ll, 2731ll, 5462ll, 10923ll, 21846ll, 43691ll, 87382ll, 174763ll, 349526ll, 699051ll, 1398102ll, 2796203ll, 5592406ll, 11184811ll, 22369622ll, 44739243ll, 89478486ll, 178956971ll, 357913942ll, 715827883ll, 1431655766ll, 2863311531ll, 5726623062ll, 11453246123ll, 22906492246ll, 45812984491ll, 91625968982ll, 183251937963ll, 366503875926ll, 733007751851ll, 1466015503702ll, 2932031007403ll, 5864062014806ll, 11728124029611ll, 23456248059222ll, 46912496118443ll, 93824992236886ll, 187649984473771ll, 375299968947542ll, 750599937895083ll, 1501199875790166ll, 3002399751580331ll, 6004799503160662ll, 12009599006321323ll, 24019198012642646ll, 48038396025285291ll, 96076792050570582ll, 192153584101141163ll, 384307168202282326ll, 768614336404564651ll, 1537228672809129302ll, 3074457345618258603ll, 6148914691236517206ll};

int MOD = 1e9 + 7;

int ge(int i) {
	int n = (1ll << i) % MOD;
	int a = st[i];
	int d = 2;
	int inv2 = 500000004ll;
	int re = (n * inv2) % MOD;
	int re2 = ((2ll * a) % MOD + (((n - 1ll) % MOD + MOD) % MOD) * d % MOD) % MOD;
	re = (re * re2) % MOD;
	return re;
}

int gee(int i, int r, int x) {
	int a = st[i];
	int n = (x - r) % MOD;
	int d = 2;
	int inv2 = 500000004ll;
	int re = (n * inv2) % MOD;

	int re2 = ((2ll * a) % MOD + (((n - 1ll) % MOD + MOD) % MOD) * d % MOD) % MOD;
	re = (re * re2) % MOD;
	return re;
}

int find(int x) {
	int re = 0;
	int r = 0;
	for (int i = 0; i < 62; ++i) {
		if ((r + (1ll << i)) <= x) {
			re = (re + ge(i)) % MOD;
			r += (1ll << i);
		} else {
			re = (re + gee(i, r, x)) % MOD;
			break;
		}
	}
	return re;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int l, r;
	cin >> l >> r;
	l = find(l - 1);
	r = find(r);
	cout << ((r - l) % MOD + MOD) % MOD;
}