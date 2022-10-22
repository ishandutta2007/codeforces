#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

int n, m, a, cnt[2500005], cnt1, arr[200005];
bool vis[2500005];
vector<int> idx[2500005], v;
vector<pii> v1[5000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a;
		arr[i] = a;
		cnt[a]++;
		idx[a].pb(i);
		if (cnt[a] >= 4){
			cout << "YES\n";
			for (int j=0; j<4; j++){
				cout << idx[a][j] << " ";
			}
			return 0;
		}
		if (cnt[a] == 2){
			v.pb(a);
			cnt1++;
		}
	}
	if (cnt1 >= 2){
		int x = v[1], y = v[0];
		cout << "YES\n";
		for (int i=0; i<2; i++){
			cout << idx[x][i] << " " << idx[y][i] << " ";
		}
		return 0;
	}
	int bad = -1;
	int ba = -1;
	if (cnt1 == 1){
		bad = idx[v[0]][0];
		ba = v[0];
		for (int i=1; i<=2*v[0]; i++){
			if (i == v[0]) continue;
			if (i > 2500000 || 2*v[0] - i > 2500000) continue;
			else if (idx[i].size() && idx[2*v[0] - i].size()){
				cout << "YES\n";
				cout << idx[i][0] << " " << idx[2*v[0] - i][0] << " " << idx[v[0]][0] << " " << idx[v[0]][1];
				return 0;
			}
		}
	}
	int t = min(n, 5000);
	for (int i=1; i<=t; i++){
		for (int j=1; j<i; j++){
			
			int x = arr[i], y = arr[j];
			if (x == ba && i !=bad) continue;
			if (y == ba && j != bad) continue;
			if (v1[x+y].size()){
				cout <<"YES\n";
				cout << v1[x+y][0].first << " " << v1[x+y][0].second << " " << i << " " << j;
				return 0;
			}
			v1[x+y].pb(mp(i,j));
		}
	}
	cout << "NO";
}