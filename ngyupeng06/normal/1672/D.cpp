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
ll arr[200005], brr[200005];
ll cnt1[200005], cnt2[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for (int i=1; i<=n; i++){
			cnt1[i] = cnt2[i] = 0;
		}
		for (int i=0; i<n; i++){
			cin >> arr[i];
		}
		for (int i=0; i<n; i++){
			cin >> brr[i];
		}
		ll cur = 0;
		cnt1[arr[cur]]=1;
		bool gd = true;
		for (int i=0; i<n; i++){
			cnt2[brr[i]]++;
			while (cur<n && (arr[cur] != brr[i] || cnt1[brr[i]] < cnt2[brr[i]])){
				cur++;
				if (cur == n){
					gd = false;
				}
				cnt1[arr[cur]]++;
			}
		}
		if (gd) cout << "yes\n";
		else cout << "no\n";
	}
}