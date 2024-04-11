#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, ans[10005];
bool vis[10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=1; i<=n; i++){
			vis[i] = false;
		}
		for (int i=1; i<=n; i++){
			if (vis[i]) continue;
			cout << "? " << i << endl;
			ll a, b;
			cin >> a;
			vector<int> v;
			v.pb(a);
			vis[a] = true;
			b = a;
			while (true){
				cout << "? " << i << endl;
				cin >> a;
				if (a == b) break;
				v.pb(a);
				vis[a] = true;
			}
			ll sz = v.size();
			for (int j=0; j<sz; j++){
				ans[v[j]] = v[(j+1)%sz];
			}
		}
		cout << "! ";
		for (int i=1; i<=n; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}