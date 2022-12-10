//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100 + 10;
int len[maxn][maxn],
	x[maxn],
	y[maxn],
	dis[maxn],
	n, d, a[maxn];

bool can(int x){
	memset(dis, -1, sizeof dis);
	dis[0] = x;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				if(k != j and dis[j] >= len[j][k])
					smax(dis[k], dis[j] - len[j][k] + a[k]);
	return dis[n - 1] >= 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	for(int i = 1; i < n - 1; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			len[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * d;
	int lo = -1,
		hi = 1e8;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(can(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << endl;
	return 0;
}