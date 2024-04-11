#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m;
string s[2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> m;
		cin >> s[0] >> s[1];
		ll ans = 0, pt = -1, prev = -1;
		for (int i=0; i<m; i++){
			int x = -1;
			if (s[0][i] != s[1][i]) x = 2;
			else if (s[0][i] == '0') x = 0;
			else x = 1;
			if (x == 2){
				ans += 2;
				if (prev == 0 && pt == 0) ans++;
				pt = 1;
				prev = 2;
			}
			else if (x == 0){
				if (prev == 0 && pt == 0) ans++;
				if (prev == 1 && pt == 0){
					ans += 2;
					pt = 1;
				}
				else pt = 0;
				prev = 0;
			}
			else {
				if (prev == 0 && pt == 0){
					ans += 2;
					pt = 1;
				}
				else pt = 0;
				prev = 1;
			}
		//	cout << ans << "\n";
		}
		if (prev == 0 && pt == 0) ans++;
		cout << ans << "\n";
	}
}