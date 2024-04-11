#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, t, a[100005], b[100005];
pll arr[100005], brr[100005];
bool vis[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=0; i<n; i++){
			cin >> arr[i].first;
			a[i] = arr[i].first;
			arr[i].second = i;
		}
		for (int i=0; i<n; i++){
			cin >> brr[i].first;
			b[i] = brr[i].first;
			brr[i].second = i;
		}
		sort(arr,arr+n);
		sort(brr,brr+n);
		for (int i=0; i<n; i++){
			vis[i] = 0;
		}
		ll cur = n-2, cur1 = n-2;
		pll x = arr[n-1], y = brr[n-1];
		ll X = x.second, Y = y.second;
		vis[x.second] = vis[y.second] = true;
		ll ca = 1e18, cb = 1e18;
		ca = min(ca, min(a[X], a[Y]));
		cb = min(cb, min(b[X], b[Y]));
		bool gd = true;
		while (gd){
			gd = false;
			while (cur >= 0 && arr[cur].first > ca){
				gd = true;
				vis[arr[cur].second] = true;
				cb = min(b[arr[cur].second], cb);
				cur--;
			}
			while (cur1 >= 0 && brr[cur1].first > cb){
				gd = true;
				vis[brr[cur1].second] = true;
				ca = min(a[brr[cur1].second], ca);
				cur1--;
			}
		}
		for (int i=0; i<n; i++){
			if (vis[i]) cout << 1;
			else cout << 0;
		}
		cout << "\n";
	}
}