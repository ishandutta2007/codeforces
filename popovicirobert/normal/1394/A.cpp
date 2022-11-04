#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;






int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, d, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
   	

   	cin >> n >> d >> m;

   	vector<ll> small(1), big(1);
   	for(i = 0; i < n; i++) {
   		int x;
   		cin >> x;
   		if(x <= m) {
   			small.push_back(x);
   		}
   		else {
   			big.push_back(x);
   		}
   	}

   	sort(next(small.begin()), small.end(), [](const int& a, const int& b) {
   			return a > b;
   	});
   	sort(next(big.begin()), big.end(), [](const int& a, const int& b) {
   			return a > b;
   	});

   	for(i = 1; i < (int)small.size(); i++) {
   		small[i] += small[i - 1];
   	}
   	for(i = 1; i < (int)big.size(); i++) {
   		big[i] += big[i - 1];
   	}


   	ll ans = small.back();
   	for(i = 1; i <= (int)big.size() - 1; i++) {
   		if(1LL * (i - 1) * (d + 1) >= n) continue;

   		ll cur = big[i];
   		
   		int need = max(0, (i - 1) * (d + 1) - ((int)big.size() - 2));
   		cur += small[(int)small.size() - need - 1];
   		
   		ans = max(ans, cur);
   	}

   	cout << ans << "\n";

    return 0;
}