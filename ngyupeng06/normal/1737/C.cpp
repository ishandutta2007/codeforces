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
ll arr[3][2];
ll cnt[3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		cnt[0] = cnt[1] = cnt[2] = 0;
		for (int i=0; i<3; i++) {
			for (int j=0; j<2; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				if (j == i) continue;
				if (arr[i][0] == arr[j][0] || arr[i][1] == arr[j][1]) cnt[i]++;
			}
		}
		cin >> a >> b;
		ll x;
		for (int i=0; i<3; i++) {

			if (cnt[i] == 2) x = i;
		}

		bool gd;
		
		if (a%2 == arr[x][0]%2 || b%2 == arr[x][1]%2) gd = true;
		else gd = false;
		
		int c = 0;
		if (arr[x][0] == 1 || arr[x][0] == n) c++;
		if (arr[x][1] == 1 || arr[x][1] == n) c++;
		
		bool gd1 = true;
		
		if (c == 2) {
			gd1 = false;
			if (a == arr[x][0] || b == arr[x][1]) gd1 = true;
		}
		
		if (gd && gd1) cout << "YES\n";
		else cout << "NO\n";
	}
}