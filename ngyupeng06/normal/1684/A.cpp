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
	while(t--){
		string s;
		cin >> s;
		int cmin = 10;
		for (auto it : s){
			cmin = min(it-'0', cmin);
		}
		if (s.length() > 2) cout << cmin;
		else cout << s[1];
		cout << nl;
		
	}
}