#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a[300005], b[300005], arr[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	for (int i=1; i<=n; i++){
		cin >> b[i];
	}
	for (int i=1; i<=n; i++){
		arr[i] = i + b[i] - a[i + b[i]];
	}
	ll cur = n;
	ll cur1 = n;
	ll cur2 = n;
	ll cmax = n - a[n];
	ll ans = 0;
	vector<int> v;
	bool gd= false;
	while (true){
		ans++;
		if (cur1 - a[cur1] < 1){
			v.pb(0);
			break;
		}
		while (cur > 0 && cur > cur1 - a[cur1]){
			cur--;
			if (arr[cur] < cmax){
				cmax = arr[cur];
				cur2 = cur;
			}
		}
		if (cmax == cur1 - a[cur1]){
			gd= true;
			break;
		}
		cur1 = cur2 + b[cur2];
		v.pb(cur2);
	}
	if (gd) cout << -1;
	else {
		cout << v.size() << "\n";
		for (auto it : v) cout << it << " ";
	}
}