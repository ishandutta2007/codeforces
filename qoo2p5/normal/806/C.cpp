/*

      #     #     #####  #####  #           #  #
     # #   # #    #      #   #  #     #     #  #
    #   # #   #   #####  #   #   #   # #   #   #
   #     #     #  #      #   #    # #   # #     
   #           #  #####  #####     #     #     @

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-7;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (int i = f; i < t; i++)

ll power(ll x, ll y, ll mod = MOD) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1, mod) * x % mod;
    } else {
        ll tmp = power(x, y / 2, mod);
        return tmp * tmp % mod;
    }
}

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

template<typename T> void read(T first, T last) {
    while (first != last) {
        cin >> *(first++);
    }
}

template<typename T> void print(T first, T last) {
    while (first != last) {
        cout << *(first++) << " ";
    }
    cout << "\n";
}  

void run();

#define TASK ""

int main() {
#ifdef LOCAL
    if (strlen(TASK) > 0) {
        cerr << "Reminder: you are using file i/o, filename: " TASK "!" << endl << endl;
    }
#endif
#ifndef LOCAL
    if (strlen(TASK)) {
        freopen(TASK ".in", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    cout << fixed << setprecision(10);
    run();
    return 0;
}

// == SOLUTION == //

const int N = (int) 1e5 + 123;
const int L = 60;

int n;
ll a[N];
int p[L];
int have[L];
int cnt[L];

int find(ll x) {
	int i = 0;
	while ((1LL << (i + 1)) <= x) i++;
	return i;
}

bool check() {
	int suff_h = 0;
	int suff_c = 0;
	for (int i = L - 1; i >= 0; i--) {
		suff_h += have[i];
		suff_c += cnt[i];
		if (suff_h > suff_c) return 0;
	}
	return 1;
}

void run() {
	cin >> n;
	read(a, a + n);
	
	set<int> ans;
	
	rep(i, 0, n) {
		int k = find(a[i]);
		if ((1LL << k) == a[i]) {
			p[k]++;
		} else {
			have[k]++;
		}
	}
	
	while (1) {
		int ptr = L - 1;
		while (!p[ptr] && ptr - 1 >= 0) ptr--;
		
		if (!p[ptr]) break;
		
		bool ok = 1;
		for (int i = 0; i <= ptr; i++) ok &= bool(p[i]);
		
		if (ok) {
			cnt[ptr]++;
			for (int i = ptr; i >= 0; i--) {
				if (!p[i]) break;
				p[i]--;
			}
		} else {
			
			for (int i = ptr; i >= 0; i--) {
				if (!p[i]) break;
				p[i]--;
				have[i]++;
			}
		}
	}
	
	rep(i, 0, n) {
		int cur_cnt = 0;
		rep(j, 0, L) cur_cnt += cnt[j];
		
		if (check()) {
			ans.insert(cur_cnt);
		} else {
			break;
		}
		
		int ptr = 0;
		while (!cnt[ptr]) ptr++;
		
		cnt[ptr]--;
		have[ptr]++;
		if (ptr > 0) cnt[ptr - 1]++;
	}
	
	if (ans.empty()) {
		cout << "-1\n";
		return;
	}
	
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}