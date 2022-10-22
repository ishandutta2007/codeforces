#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c;
ll arr[20];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		ll cnt = 0;
		for (int i=0;i<n;i++){
			cin >> arr[i];
			while (arr[i]%2==0){
				arr[i]/=2;
				cnt++;
			}
		}
		sort(arr,arr+n);
		for (int i=0; i<cnt; i++){
			arr[n-1] *= 2;
		}
		ll sum =0;
		for (int i=0; i<n; i++){
			sum += arr[i];
		}
		cout << sum << "\n";
	}
}