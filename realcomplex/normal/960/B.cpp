#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))

int main(){
	fastIO;
	int n;
	cin >> n;
	int k1,k2;
	cin >> k1 >> k2;
	ll a[n];
	ll b[n];
	for(int i = 0;i<n;i++)
		cin >> a[i];
	for(int i = 0;i<n;i++)
		cin >> b[i];
	ll maxs;
	int u;
	while(k1 + k2 > 0){
		maxs = 0;
		u = 0;
		for(int i = 0;i<n;i++){
			if(ab(a[i] - b[i]) > maxs)
				maxs = ab(a[i]-b[i]),u = i;
		}
		if(k1 > k2){
			if(a[u] > b[u]){
				a[u]--;
			}
			else{
				a[u]++;
			}
			k1--;
		}
		else{
			if(b[u] > a[u]){
				b[u]--;
			}
			else{
				b[u]++;
			}
			k2--;
		}
	}
	ll ans = 0;
	for(int i = 0;i<n;i++)
		ans += (a[i]-b[i]) * (a[i]-b[i]);
	cout << ans;
	return 0;
}