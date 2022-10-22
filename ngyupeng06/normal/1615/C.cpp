#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t;
string s, s1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		cin >> s >> s1;
		ll cnt =0, cnt1 =0, cnt2=0, cnt3=0;
		for (int i=0; i<n ;i++){
			if(s[i] != s1[i]){
				cnt++;
				if (s[i] == '1')cnt1++;
			}
			else {
				cnt2++;
				if (s[i] == '1') cnt3++;
			}
		}
		if (cnt%2 == 1){
			if (n%2 == 1) cout << -1;
			else if (cnt3 - (cnt2-cnt3) == 1) cout << n-cnt;
			else cout << -1;
		}
		else {
			ll ans = 2e18;
			if (n%2 == 1 && cnt3 - (cnt2-cnt3 ) == 1){
				ans = min(ans,n-cnt);
			
			}
			if (cnt-cnt1 == cnt1) ans = min(ans,cnt);
			if (ans !=2e18)cout << ans;
			else cout << -1;
		}
		cout << '\n';
	}
}