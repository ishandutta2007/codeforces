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
ll arr[200005];
ll sum[200005];
ll cnt[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	string s;
	cin >> s;
	ll cur = 0;
	for (int i=0; i<n-1; i++){
		if (s[i] == s[i+1]){
			arr[i] = 1;
			cur++;
		}
		if (i%2) arr[i] *= -1;
		if (cur%2) arr[i] *= -1;
	}
	for (int i=1; i<=n; i++){
		sum[i] = sum[i-1] + arr[i-1];
		cnt[i] = cnt[i-1] + abs(arr[i-1]);
	}
	for (int i=0; i<m; i++){
		ll a, b;
		cin >> a >> b;
		ll v1 = abs(sum[b-1] - sum[a-1]);
		ll v2 = cnt[b-1] - cnt[a-1];
		cout << (v1+v2)/2 + 1 << nl;
	}
}