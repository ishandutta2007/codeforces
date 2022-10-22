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
		ll sum =0;
		for (int i=0; i<n; i++){
			cin >>m;
			sum+= m;
			
		}
		if (sum %n ==0 ) cout << 0;
		else cout << 1;
		cout << "\n";
	}
}