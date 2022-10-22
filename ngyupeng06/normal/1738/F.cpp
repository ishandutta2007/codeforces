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

ll n, m, q, k, t, a, b, c;
pll arr[1005];
bool vis[1005];
ll p[1005];
ll col[1005];

int findSet(int id) { 
	return (p[id] == id) ? id : (p[id] = findSet(p[id])); 
} 
bool sameset(int a, int b) { 
	return findSet(a) == findSet(b); 
} 
void mergeset(int a, int b) { 
	int pa = findSet(a), pb = findSet(b); 
	p[pa] = pb; 
}


int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			p[i] = i;
			cin >> arr[i].first;
			arr[i].second = i;
			vis[i] = false;
		} 
		sort(arr+1, arr + n+1);
		for (int i = n; i >= 1; i--) {
			ll x = arr[i].second, y = arr[i].first;
			if (vis[x]) continue;
			vis[x] = true;
			for (int j=0; j<y; j++){
				cout << "? " << x << endl;
				cin >> a;
				if (vis[a]){
					mergeset(x, a);
					break;
				}
				else {
					mergeset(x,a);
					vis[a] = true;
				}
			}
		}
		ll cnt = 0;
		for (int i = 1; i <= n; i++){
			vis[i] = false;
		}
		vector<int> v;
		for (int i = 1; i <= n; i++){
			ll x = findSet(i);
			if (!vis[x]){
				vis[x] = true;
				cnt++;
				col[x] = cnt;
			}
			v.pb(col[x]);
		}
		cout << "! ";
		for (auto it : v) cout << it << " ";
		cout << endl;
	}

}