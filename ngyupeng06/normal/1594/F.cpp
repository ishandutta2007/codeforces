#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> a >> b >> c;
		if (c == a) cout << "YES\n";
		else if (a < 2*b){
			if (c > b) cout << "NO\n";
			else {
				ll x = b / c;
				ll y = b%c + 2*c*x;
				if (y <= a) cout << "NO\n";
				else cout << "YES\n";
			}
		}
		else cout << "NO\n";
	}
}