#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, arr[100005], l[100005], r[100005], thing;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	l[0] = 0;
	r[n-1] = 0;
	for (int i=1; i<n; i++){
		if (arr[i] > arr[i-1]) l[i] = l[i-1] + 1;
		else l[i] = 0;
		thing = max(thing, l[i]);
	}
	for (int i=n-2; i>=0; i--){
		if (arr[i] > arr[i+1]) r[i] = r[i+1] + 1;
		else r[i] = 0;
		thing = max(thing, r[i]);
	}
	ll ans = 0, xx = 0;
	for (int i=0; i<n; i++){
		if (l[i] == r[i] && l[i] == thing) ans++;
		if (l[i] == thing || r[i] == thing) xx++;
	}
	if (xx == 1 && thing % 2 == 0) cout << ans;
	else cout << 0;
}