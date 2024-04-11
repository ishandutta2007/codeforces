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
		string s;
		bool gd = false;
		map<string, int> ma, ma1;
		for (int i=0; i<n; i++){
			cin >> s;
			if (s.length() == 1){
				gd = true;
			}
			else if (s.length() == 2){
				if (s[0] == s[1]){
					gd = true;
				}
				else {
					if (ma[s] == 1 || ma1[s] == 1){
						gd = true;
					}
					string s1 = "";
					s1 += s[1];
					s1 += s[0];
					ma[s1] = 1;
					ma1[s1] = 1;
				}
			}
			else {
				if (s[0] == s[2]){
					gd = true;
				}
				else {
					string s1 = "", s2 = "", s3 = "";
					s1 += s[1];
					s1 += s[0];
					s2 += s[2];
					s2 += s[1];
					s2 += s[0];
					s3 += s[1];
					s3 += s[2];
					if (ma[s3] == 1 || ma1[s] == 1){
						gd = true;
					}
					ma1[s1] = ma1[s2] = 1;
				}
			}
		}
		if (gd) cout << "YES\n";
		else cout << "NO\n";
	}	
}