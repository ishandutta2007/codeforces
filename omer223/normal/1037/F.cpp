#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0) 
#define foru(i, k, n) for (int i = k; i < n; i++) 
#define ford(i, k, n) for (int i = k; i >= n; i--) 
#define pb push_back
#define ff first 
#define ss second 

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string> 
#include <list> 
#include <queue> 
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> dat;

const ll mod = 1e9 + 7;

void imult(ll& lhs, const ll& rhs) {
	lhs = ((lhs % mod) * (rhs % mod)) % mod;
}

void iadd(ll& lhs, const ll& rhs) {
	lhs = ((lhs%mod) + (rhs%mod)) % mod;
}

void isubt(ll& lhs, const ll& rhs) {
	ll ret = (lhs - rhs) % mod;
	lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll& lhs, const ll& rhs) {
	if (rhs == 0)return 1;
	ll ret = bpw(lhs, rhs >> 1);
	imult(ret, ret);
	if (rhs & 1) imult(ret, lhs);
	return ret;
}

ll inv(const ll& x) {
	return bpw(x, mod - 2);
}

ll mult(const ll& lhs, const ll& rhs) {
	return ((lhs % mod) * (rhs % mod)) % mod;
}

ll add(const ll& lhs, const ll& rhs) {
	return ((lhs%mod) + (rhs%mod)) % mod;
}

ll subt(const ll& lhs, const ll& rhs) {
	ll ret = (lhs - rhs) % mod;
	return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll& lhs, const ll& rhs) {
	return mult(lhs, inv(rhs));
}



const int sz = 1e6 + 5;
int n, k;
vector<int> a;
vector<pii> retarr[sz];
ll stksum[sz], pans[sz];

void prepans() {
	multiset<int, greater<int>> st;
	ford(i, n - 1, n - k + 1)st.insert(a[i]);
	ford(i, n - k, 0) {
		st.insert(a[i]);
		pans[i] = *st.begin();
		st.erase(st.find(a[i + k - 1]));
	}
}

void input() {
	scanf("%d %d", &n, &k); 
	a.resize(n);
	foru(i, 0, n)
		scanf("%d", &a[i]);
}

int main() {
	//fast;
	input();
	prepans();
	ll tot = 0, myans;
	int stknum;
	ford(i, n - k, max(n - 2 * k + 2,0)) {
		myans = pans[i];
		stknum = i % (k - 1);
		tot += myans;
		tot %= mod;
		retarr[i % (k - 1)].pb({ myans,1 });
		stksum[i % (k - 1)] = myans;
	}
	ford(i, n - 2 * k + 1, 0) {
		myans = pans[i];
		stknum = i % (k - 1);
		int occ = 1;
		while (!retarr[stknum].empty() && retarr[stknum].back().ff <= myans) {
			isubt(stksum[stknum], mult(retarr[stknum].back().ss, retarr[stknum].back().ff));
			occ += retarr[stknum].back().ss;
			retarr[stknum].pop_back();
		}
		iadd(stksum[stknum], mult(occ, myans));
		retarr[stknum].pb({ myans,occ });
		iadd(tot, stksum[stknum]);
	}
	printf("%lld\n", tot);
	return 0;
}