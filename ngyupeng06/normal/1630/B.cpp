#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t;
ll arr[200005], cnt[200005], sum[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i=1; i<=n; i++){
			cnt[i] = 0;
		}
		for (int i=1; i<=n; i++){
			cin >> arr[i];
			cnt[arr[i]]++;
		}
		for (int i=1; i<=n; i++){
			sum[i] = sum[i-1] + cnt[i];
		}
		ll cur = 1;
		ll opt = 2e9, al = -1, ar = -1;
		for (int i=1; i<=n; i++){
			while (cur < i) cur++;
			while (cur <= n && sum[cur] - sum[i-1] < m + n + sum[i-1] - sum[cur]){
				cur++;
			}
			if (cur <= n){
				if (opt > cur - i + 1){
					opt = cur - i + 1;
					al = i, ar = cur;
				}
			}
		}
		cout << al << " " << ar << '\n';
		ll cl = 1, cnn = 0, cnm = 0;
		for (int i=1; i<=n; i++){
			if (arr[i] <= ar && arr[i] >= al) cnn++;
			else cnn--;
			if (cnn == 1 && cnm != m-1){
				cout << cl << " " << i << "\n";
				cl = i+1;
				cnm++;
				cnn = 0;
			}
		}
		cout << cl << " " << n << "\n";
	}
}