#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c, arr[40];

ll gcd(ll x, ll y){
	if (x > y) swap(x,y);
	if (x == 0) return y;
	return gcd(y%x, x);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=0; i<30; i++) arr[i] = 0;
		for (int i=0; i<n; i++){
			cin >> a;
			for (int j=0; j<30; j++){
				if (a & (1 << j)) arr[j]++;
			}
		}
		ll GG = 0;
		for (int i=0; i<30; i++){
			GG = gcd(arr[i], GG);
		}
		vector<int> v;
		for (int i=1; i<=n; i++){
			if (GG % i == 0) cout << i << " ";
		}
		cout << "\n";
	}
}