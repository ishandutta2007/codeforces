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

const int N = 1005;
int tt[N];

int main(){
	fastIO;
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n;i ++ ){
		cin >> tt[i];
	}
	int u, v;
	int ans = 0;
	for(int i = 0; i < m ; i ++ ){
		cin >> u >> v;
		ans += min(tt[u], tt[v]);
	}
	cout << ans << "\n";
	return 0;
}