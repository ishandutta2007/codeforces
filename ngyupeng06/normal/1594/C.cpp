#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b;
char c;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> c >> s;
		ll l = s.length();
		bool gd = true, gd1 = true;
		ll idx = -1;
		for (int i=0; i<l; i++){
			if (s[i] != c) gd = false;
			else idx = i+1;
		}
		if (s[l-1] != c) gd1 = false;
		if (gd){
			cout << 0 << "\n";
			continue;
		}
		else if (gd1){
			cout << 1 << "\n" << l << "\n";
			continue;
		}
		else {
			if (idx <= l/2) cout << 2 << "\n" << l << " " << l-1 << "\n";
			else cout << 1 << "\n" << idx << "\n";
		}
	}
}