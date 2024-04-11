#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;
ll arr[1005];
ll par[1005], ch[1005];
vector<int> v[1005];

ll level = 0;

bool dfs(int x){
	ch[x] = level;
	for (auto it : v[x]){
		if (par[it] == -1){
			par[it] = x;
			return true;
		}
		else if (ch[par[it]] != level && dfs(par[it])){
			par[it] = x;
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	bool gd = true;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		if (arr[i] > (m-1)/2) gd = false;
	}
	if (!gd){
		cout << -1;
		return 0;
	}
	sort(arr, arr+n);
	int a = n;
	for (int i=0; i<n; i++){
		if (arr[i]*3 > m){
			a = i;
			break;
		}
	}
	if (a == n){
		cout << n << nl;
		for (int i=0; i<n; i++){
			cout << 2*arr[i] << " " << 3*arr[i] << nl;
		}
		return 0;
	}
	for (int i=0; i<n; i++) par[i] = -1;
	for (int i=0; i<a; i++){
		for (int j=a; j<n; j++){
			if (arr[j]%arr[i] == 0 && arr[j]*2 + arr[i] <= m){
				v[j].pb(i);
				v[i].pb(j);
			}
		} 
	}
	for (int i=a; i<n; i++){
		level++;
		bool gd1 = dfs(i);
		if (!gd1) gd = false;
	}
	if (!gd){
		cout << -1;
		return 0;
	}
	cout << a << nl;
	for (int i=0; i<a; i++){
		if (par[i] == -1){
			cout << 2*arr[i] << " " << arr[i]*3 << nl;
		}
		else {
			ll x = par[i];
			cout << arr[x] + arr[i] << " " << 2*arr[x] + arr[i] << nl;
		}
	}
}