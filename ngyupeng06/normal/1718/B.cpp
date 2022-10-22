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
ll f[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		priority_queue<pll> pq;
		cin >> n;
		ll sum = 0;
		for (int i=0; i<n; i++){
			ll a;
			cin >> a;
			sum += a;
			
			pq.push(mp(a,(ll)1006));
		}
		f[0] = 1;
		f[1] = 1;
		ll sum1 = 0;
		ll gd = -1;
		for (int i=0; i<1000; i++){
			if (i > 1) f[i] = f[i-1] + f[i-2];
			sum1 += f[i];
			if (sum1 > sum) break;
			else if (sum1 == sum){
				gd = i;
				break;
			}
		}
		if (gd == -1){
			cout << "NO" << nl;
		}
		else {
			ll cnt = 1000;
			bool gd1 = false;
			while (!pq.empty()){
				pll x = pq.top();
				if (x.first < f[gd] || x.second == cnt){
					gd1 = true;
					break;
				}
				pq.pop();
				if (x.first-f[gd] != 0) pq.push(mp(x.first-f[gd], cnt-1));
				cnt--;
				gd--;
			}
			if (gd1) cout << "NO" << nl;
			else cout << "YES" << nl;
		}
	}
}