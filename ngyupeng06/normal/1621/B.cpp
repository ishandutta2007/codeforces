#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		ll a, b, c, cmin = 2e9, cmax = 0, cmn = 0, cmx = 0, ans = 2e9;
		for (int i=0; i<n; i++){
			cin >> a >> b >> c;
			if (a < cmin){
				cmn = c;
				cmin = a;
				ans = 2e9;
			}
			if (b > cmax){
				cmx = c;
				cmax = b;
				ans = 2e9;
			}
			if (a == cmin){
				cmn = min(cmn, c);
			}
			if (b == cmax){
				cmx = min(cmx, c);
			}
			if (a == cmin && b == cmax){
				ans = min(ans, c);
			}
			cout << min(ans, cmn + cmx);
			cout << "\n";
		}
	}
}