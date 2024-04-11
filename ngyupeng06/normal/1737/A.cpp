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
		string s;
		cin >> s;
		int cnt[26];
		for (int i=0; i<26; i++) {
			cnt[i] = 0;
		}
		for (int i=0; i<n; i++) {
			cnt[s[i] - 'a']++;
		}
		
		string ans = "";
		int c = n / m;
	
		for (int i = 0; i < m; i++) {
			int x = 0;
			for (int i = 0; i < min(c, 25); i++) {
				if (cnt[i]) {
					cnt[i]--;
					x = i+1;
				}
				else break;
			}
			char cc = 'a' + x;
			ans += cc;
		}
		
		cout << ans << nl;
	}
}