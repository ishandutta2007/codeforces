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
ll r[1000005], c[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		string s;
		cin >> s;
		ll cnt = 0, cnt1 = 0;
		for (int i=0; i<m; i++){
			c[i] = r[i] = 0;
		}
		for (int i=0; i<m; i++){
			ll a = s[i] - '0';
			cnt += a;
			c[i] += a;
			if (a == 1) cnt1++;
			if (cnt) r[i] = 1;
			cout << r[i] + cnt1 << " ";
		}
		for (int i=m; i<n*m; i++){
			ll a = s[i] - '0';
			if (s[i-m] == '1') cnt--;
			cnt += a;
			c[i%m] += a;
			if (a == 1 && c[i%m] == 1) cnt1++;
			r[i] = r[i-m];
			if (cnt) r[i]++;
			cout << r[i] + cnt1 << " ";
		}
		cout << nl;
	}
}