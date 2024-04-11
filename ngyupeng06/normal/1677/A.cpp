#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t, arr[5005];
int ans[5005][5005], ans1[5005][5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for (int i=1; i<=n; i++){
			cin >> arr[i];
		}
		for (int i=0; i<5005; i++){
			ans1[n+1][i] = 0;
		}
		for (int i=1; i<=n; i++){
			for (int j=1; j<i; j++){
				ans[j][i]=ans[j-1][i];
				if (arr[j] < arr[i]) ans[j][i]++;
			}
		}
		for (int i=1; i<=n; i++){
			for (int j=n; j>i; j--){
				ans1[j][i]=ans1[j+1][i];
				if (arr[j] < arr[i]) ans1[j][i]++;
			}
		}
		ll sum = 0;
		for (int i=1; i<=n; i++){
			for (int j=i+1; j<=n; j++){
				ll a = ans[i-1][j];
				ll b = ans1[j+1][i];
				sum += a*b;
			}
		}
		cout << sum << '\n';
	}
}