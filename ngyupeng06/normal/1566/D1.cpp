#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, a;
pll arr[305];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tc=0; tc<t; tc++){
		cin >> n >> m;
		for (int i=0; i<n*m; i++){
			cin >> a;
			arr[i] = mp(a,-i);
		}
		sort(arr,arr+m);
		ll cnt = 0;
		for (int i=0; i<m; i++){
			for (int j=0; j<i; j++){
				if (arr[j].second > arr[i].second) cnt++;
			}
		}
		cout << cnt << "\n";
	}
}