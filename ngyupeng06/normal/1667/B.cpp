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
ll arr[500007];
ll ans[500007];

ll ft[500007][2];

void update(ll x, ll v, ll c) {
	for (; x < 500007; x += x & -x) ft[x][c] = max(ft[x][c], v);
}

ll query(ll x, ll c) {
	ll sum = -2e9;
	for (; x; x -= x & -x) sum = max(sum, ft[x][c]);
	return sum;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin>>n;
	ll sum = 0;
	vector<ll> v;
	for(int i=0; i<n+5; i++) ans[i] = -2e9;
	for (int i=1; i<=n; i++){
		ll a;
		cin >> a;
		sum += a;
		arr[i] = sum;
		v.pb(sum);
//		cout << arr[i] << "\n";
	}
	v.pb(0);
	sort(v.begin(), v.end());
	arr[0] = 0;
	for (int i=0; i<=n; i++){
		arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 2;
	}
	for (int i=0; i<n+5; i++){
		ft[i][0] = ft[i][1] = -2e9;
	}
	update(arr[0], 0, 0);
	update(n+5 - arr[0], 0, 1);
	ll ans1 = 0;
	ans[arr[0]] = 0;
//	cout << arr[0] << "\n";
	for (int i=1; i<=n; i++){
//		cout << "test " << arr[i] << "\n";
		ll a=0, b=0, c=0;
		a = query(arr[i] - 1, 0) + i;
		b = query(n+5 - arr[i] - 1, 1) - i;
		c = ans[arr[i]];
		ll d = max(a,max(b,c));
		
		if (i==n) ans1 = d;
		
		update(arr[i], d - i, 0);
		update(n+5-arr[i], d+i, 1);
		ans[arr[i]] = max(ans[arr[i]], d);
//		cout << d << "\n";
	}
	cout << ans1 << '\n';
}
}