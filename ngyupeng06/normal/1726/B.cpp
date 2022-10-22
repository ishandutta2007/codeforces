#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (m < n){
			cout << "No\n";
			continue;
		}
		
		if (n % 2 == 1) {
			cout << "Yes\n";
			for (int i=0; i<n-1; i++) {
				cout << "1 ";
			}
			cout << m - (n-1) << nl;
		}
		
		else {
			if (m % 2){
				cout << "No\n";
			}
			else {
				cout << "Yes\n";
				for (int i = 0; i < n-2; i++){
					cout << "1 ";
				}
				ll x = (m - (n-2) )/ 2;
				cout << x << " " << x << nl;
			}
		}
	}
}