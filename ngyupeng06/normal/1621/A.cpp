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
		cin >> n >> m;
		if (m <= (n+1)/2){
			ll cnt = 0;
			for (int i=0; i<n; i++){
				for (int j=0; j<n; j++){
					if (i == j && j%2 == 0 && cnt < m){
						cout << 'R';
						cnt++;
					}
					else cout << '.';
				}
				cout << "\n";
			}
		}
		else {
			cout << -1 << "\n";
		}
	}
}