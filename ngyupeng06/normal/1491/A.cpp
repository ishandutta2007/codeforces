#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, arr[100005], cnt[2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	while(m--){
		ll a, b;
		cin >> a >> b;
		if (a == 2){
			if (cnt[1] >= b) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else{
			cnt[arr[b]]--;
			cnt[1-arr[b]]++;
			arr[b] = 1 - arr[b];
		}
	}
}