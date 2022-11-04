#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;


const int X = (int)1e7;

int Count[2 * X + 1];


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);	

    for (int i = 2; i <= 2 * X; i++) {
    	if (Count[i] == 0) {
	    	for (int j = i; j <= 2 * X; j += i) {
	    		Count[j]++;
	    	}
    	}
    }
		
	int q;
	cin >> q;

	while (q--) {
		int c, d, x;
		cin >> c >> d >> x;

		ll ans = 0;

		auto check = [&](ll g) -> void {
			ll prd = x + 1LL * d * g;

			if (prd % c != 0)
				return;

			prd /= c;

			if (prd % g != 0)
				return;

			prd /= g;

			ans += (1LL << Count[prd]);
		};

		int i = 1;
		while (i * i <= x) {
			if (x % i == 0) {
				check(i);

				if (i * i < x) {
					check(x / i);
				}
			}
			i++;
		}

		cout << ans << "\n";
	}
	

    return 0;
}