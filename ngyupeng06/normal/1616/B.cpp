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
		string s;
		cin >> n >> s;
		string ans = "";
		int x = 1000000;
		for (int i=0; i<n; i++){
			int y = s[i];
			if (y > x) break;
			x = y;
			ans += s[i];
		}
		string ans2 = ans;
		for (int i=0; i<ans.length(); i++){
			ans2 += ans[ans.length()-1-i];
		}
		string thing = "";
		thing += s[0];
		thing += s[0];
		if (thing < ans2) ans2 = thing;
		cout << ans2 << "\n";
	}
}