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

ll n, m, t, a, b, c;
ll arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		bool gd = true;
		for (int i=0; i<n; i++) {
			cin >> arr[i];
			if (arr[i] == 1) gd = false;
		}
		if (!gd) cout << "YES\n";
		else cout << "NO\n";
	}
}