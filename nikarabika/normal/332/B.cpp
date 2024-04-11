#include <bits/stdc++.h>

using namespace std;

#define L first
#define R second
#define MP make_pair

typedef long long int ll;

const int maxn = 2e5 + 10;
ll a[maxn];
ll s[maxn];
pair<ll, int> Max[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= k; i++)
		s[i] = s[i - 1] + a[i];
	for(int i = k + 1; i <= n; i++)
		s[i] = s[i - 1] + a[i] - a[i - k];
	Max[n] = MP(s[n], n);
	for(int i = n - 1; i > 0; i--)
		if(s[i] >= Max[i + 1].L)
			Max[i] = MP(s[i], i);
		else
			Max[i] = Max[i + 1];
	ll ans = 0, ans1, ans2;
	for(int i = k; i + k <= n; i++){
		ll x = s[i] + Max[i + k].L;
		if(x > ans){
			ans = x;
			ans1 = i - k + 1;
			ans2 = Max[i + k].R - k + 1;
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}