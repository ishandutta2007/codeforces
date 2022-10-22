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
		ll ans = 0;
		int cnt[105];
		for (int i=0; i<105; i++) cnt[i] = 0;
		for (int i=0; i<n; i++){
			ll a;
			cin >> a;
			if (a < 0) a = -a;
			if (cnt[a] < 2){
				if (a == 0 && cnt[a] == 0) cnt[0] = 1, ans++;
				else if (a != 0) cnt[a]++, ans++;
			}
		}
		cout << ans << '\n';
	}
}