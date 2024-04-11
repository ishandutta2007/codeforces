#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

int n, m, t;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> s;
		int l = s.length();
		bool gd= true;
		char a = s[0];
		for (int i=1; i<l; i++){
			if (s[i] != a) gd = false;
		}
		if (gd) cout << s << "\n";
		else {
			string ans = "";
			ans += s[0];
			for (int i=1; i<l; i++){
				if (s[i] == s[i-1]){
					if (s[i] == '0'){
						ans += '1';
					}
					else {
						ans += '0';
					}
					
				}
				ans += s[i];
			}
			if (ans.length()%2 == 1){
				if (ans[0] == '0') ans += '1';
				else ans += '0';
			}
			cout << ans << "\n";
		}
	}
}