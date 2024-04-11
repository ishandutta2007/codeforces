#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)1e5 + 9;

vector<int> T[N];

int bit[N];

ll ans, way;

vector<int> bi[2];

void dfs(int u, int bt){
	bit[u] = bt;
	bi[bt].push_back(u);
	for(auto x : T[u]){
		if(bit[x] == -1){
			dfs(x, 1 - bt);
		}
		else{
			if(bit[x] == bt){
				cout << "0 1\n";
				exit(0);
			}
		}
	}
}

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	if(m == 0){
		ans = (1ll * n * (n - 1) * (n - 2)) / 6ll;
		cout << 3 << " " << ans << "\n";
		return 0;
	}
	ans = (ll)1e9;
	way = 0;
	for(int i = 1; i <= n; i ++ )
		bit[i] = -1;
	int u, v;
	for(int i = 0;i < m;i ++ ){
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	ll s1, s2, s3;
	ll sz;
	int mxbit;
	for(int i = 1 ;i <= n; i ++ ){
		bi[0].clear();
		bi[1].clear();
		if(bit[i] == -1){
			dfs(i, 0);
			if(bi[0].size() + bi[1].size() == 1){
				continue;
			}
			else if(bi[0].size() + bi[1].size() == 2){
				if(ans > 2)
					way = 0;
				if(ans >= 2){
					ans = 2;
					way += n - 2;
				}
			}
			else{
				if(ans > 1){
					ans = 1;
					way = 0;
				}
				s1 = bi[0].size();
				s2 = bi[1].size();
				s3 = n - 2;
				way += (s1 * (s1 - 1)) / 2;
				way += (s2 * (s2 - 1)) / 2;
			}
		}
	}
	cout << ans << " " << way << "\n";
	return 0;
}