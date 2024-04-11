#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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
		n = s.length();
		bool gd=false, gd1 = false;
		ll a = 0, b = 0;
		for (int i=0; i<n;i++){
			if (s[i] == 'B'){
				gd = true;
				b++;
				if (b > a) gd1 = true;
			}
			else {
				a++;
			}
		}	
		if (gd1 || s[n-1] == 'A') cout << "NO\n";
		else cout << "YES\n";
	}
}