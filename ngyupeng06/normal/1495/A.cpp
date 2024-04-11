#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll cntx, cnty, n, m, t;
ll x[100005], y[100005], a, b;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		cntx = cnty = 0;
		for (int i=0; i<2*n; i++){
			cin >> a >> b;
			if (b == 0) x[cntx++] = abs(a);
			else y[cnty++] = abs(b);
		}
		sort(y, y+n);
		sort(x, x+n);
		long double ans = 0;
		for (int i=0; i<n; i++){
			long double xx = x[i] * x[i], yy = y[i] * y[i];
			ans += sqrt(xx + yy);
		}
		cout << setprecision(10) << ans << "\n";
	}
}