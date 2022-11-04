#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int


    
using namespace std;

  
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
	int i, n;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);
		
	cin >> n;

	vector <int> a(n + 1), sp(n + 1);
	vector <ll> sum(n + 1);

	for(i = 1; i <= n; i++) {
		cin >> a[i];
		sp[i] = sp[i - 1] + a[i];
		sum[i] = sum[i - 1] + i * a[i];
	}

	ll ans = 1e18;

	auto check = [&](int x) {
		ll cur = 0;
		int i = 1;
		while(i <= n) {
			int j = i;
			while(j <= n && sp[j] - sp[i - 1] < x) {
				j++;
			}

			if(j == n + 1) {
				break;
			}


			ll mn = 1e18;
			int aux = i - 1;

			while(i <= j) {
				mn = min(mn, 1LL * i * (sp[i] - sp[aux]) - (sum[i] - sum[aux]) + sum[j] - sum[i] - 1LL * i * (sp[j] - sp[i]));
				i++;
			}	

			cur += mn;
		}

		//cerr << x << " " << cur << "\n";
		
		return cur;
	};

	for(int d = 1; d * d <= sp[n]; d++) {
		if(sp[n] % d) continue;

		if(d > 1) {
			ans = min(ans, check(d));
		}
		if(sp[n] / d > 1) {
			ans = min(ans, check(sp[n] / d));
		}
	}

	if(ans == 1e18) ans = -1;

	cout << ans;
		
	return 0;
}