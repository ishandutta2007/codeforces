#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int


    
using namespace std;

const int MAXN = (int)  1e6;

bool ciur[MAXN + 1];
  
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
	int i, n;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);

	for(i = 2; i * i <= MAXN; i++) {
		if(ciur[i] == 0) {
			for(int j = i * i; j <= MAXN; j += i) {
				ciur[j] = 1;
			}
		}
	}
		
	cin >> n;

	vector <int> a(n + 1);
	vector <ll> b(n + 1);

	vector <ll> pref(n + 1), suff(n + 2);

	ll sum = 0;
	for(i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	auto check = [&](ll x) {
		for(i = 1; i <= n; i++) {
			b[i] = a[i] % x;
			pref[i] = suff[i] = 0;
		}

		ll ans = 0;
		i = 1;

		while(i <= n) {
			ll cur = 0;
			int j = i;
			while(j <= n && cur + b[j] < x) {
				cur += b[j++];
			}

			if(j == n + 1) {
				break;
			}

			ll aux = b[j] - (x - cur);
			b[j] = x - cur;

			pref[i - 1] = 0;

			ll cnt = 0;
			for(int p = i; p <= j; p++) {
				pref[p] = pref[p - 1] + cnt;
				cnt += b[p];
			}

			cnt = 0, cur = 1e18;
			for(int p = j; p >= i; p--) {
				suff[p] = suff[p + 1] + cnt;
				cnt += b[p];

				cur = min(cur, pref[p] + suff[p]);
			}

			ans += cur;

			//cerr << x << " " << i << " " << j << " " << ans <<  "\n";

			b[j] = aux;
			i = j;
		}

		return ans;
	};

	ll ans = 1e18;
	for(int x = 2; x <= MAXN; x++) {
		if(ciur[x] == 0 && sum % x == 0) {
			ans = min(ans, check(x));
			while(sum % x == 0) {
				sum /= x;
			}
		}
	}

	if(sum > 1) {
		ans = min(ans, check(sum));
	}

	if(ans == 1e18) ans = -1;

	cout << ans;
		
	return 0;
}