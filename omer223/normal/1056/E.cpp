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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const ll sz = 2e6;
string s, t;

ll modpow(ll a, ll b, ll MOD) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a % MOD; a = a * a % MOD; }return res; }


struct SingHash {
private:
public:
	ll p, m;
	vector<ll> pows, invpows, table;
	SingHash(ll prime, ll mod, ll MAX_SIZE) {
		p = prime;
		m = mod;
		pows.resize(MAX_SIZE);
		invpows.resize(MAX_SIZE);
		for (ll i = 0; i < MAX_SIZE; i++) {
			if (!i)pows[i] = 1;
			else pows[i] = (pows[i - 1] * p) % m;
		}
		invpows[MAX_SIZE - 1] = modpow(pows[MAX_SIZE - 1], m - 2, m);
		for (ll i = MAX_SIZE - 2; i >= 0; i--)invpows[i] = (invpows[i + 1] * p) % m;
	}
	ll compHash(vector<ll> v) { //ll OR STRING??
		ll res = 0;
		for (ll i = 0; i < v.size(); i++) {
			res += (pows[i] * (v[i] + 1)); res %= m; //CHANGE ACCORDINGLY
		}
		return res;
	}
	void compArr(vector<ll> v) {
		if (!v.size()) return;
		vector<ll> res(v.size(), 0);
		ll tmp;
		for (ll i = 0; i < v.size(); i++) {
			tmp = (pows[i] * (v[i] + 1)) % m; //CHANGE
			if (!i)res[i] = tmp;
			else res[i] = (res[i - 1] + tmp) % m;
		}
        table = res;
	}
	ll subarrHash(ll i, ll j) {
		if (i > j)return -1;
		if (!i)return table[j];
		return ((table[j] - table[i - 1] + m) * invpows[i]) % m;
	}
};

SingHash* sh1,*sh2;

pll calcHash(ll i, ll j) {
    return { sh1->subarrHash(i,j),sh2->subarrHash(i,j) };
}

int main() {
    fast;
    cin >> s >> t;
    ll n = s.length(), m = t.length(), zcnt = 0, ocnt = 0;
    for (char c : s) {
        zcnt += (c == '0');
        ocnt += (c == '1');
    }
	vector<ll> harr(m);
	foru(i, 0, m)harr[i] = (t[i] - 'a' + 1);
    sh1 = new SingHash(33, 1e9 + 7, sz);
    sh1->compArr(harr);
    sh2 = new SingHash(37, 1e9 + 9, sz);
    sh2->compArr(harr);

    ll cnt = 0;
    for (ll zlen = 1; zlen <= m; zlen++) {
        ll olen = m - zlen * zcnt;
        if (olen % ocnt == 0 && olen > 0)olen /= ocnt;
        else continue;
        pll zhash = { -1,-1 }, ohash = { -1,-1 };
        ll ptr = 0, idx = 0;
        bool good = 1;
        while (ptr < m && idx < n) {
            if (s[idx] == '0') {
                ll nptr = ptr + zlen - 1;
                if (zhash.ff == -1)zhash = calcHash(ptr, nptr);
                else {
                    if (zhash != calcHash(ptr, nptr)) {
                        good = 0;
                        break;
                    }
                }
                ptr = nptr + 1;
                idx++;
            }
            else {
                ll nptr = ptr + olen - 1;
                if (ohash.ff == -1)ohash = calcHash(ptr, nptr);
                else {
                    if (ohash != calcHash(ptr, nptr)) {
                        good = 0;
                        break;
                    }
                }
                ptr = nptr + 1;
                idx++;
            }
        }
        if (good)cnt += (zhash != ohash);
    }
    cout << cnt;
    return 0;
}