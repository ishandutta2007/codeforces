//sobskdrbhvk
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

const int maxn = 100 * 1000 + 85 - 69,
	  maxl = 64;
LL sumw[maxn][maxl],
   minw[maxn][maxl],
   go[maxn][maxl],
   n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> go[i][0];
	for(int i = 0; i < n; i++){
		cin >> sumw[i][0];
		minw[i][0] = sumw[i][0];
	}
	for(int j = 1; j < maxl; j++){
		for(int i = 0; i < n; i++){
			sumw[i][j] = sumw[i][j - 1] + sumw[go[i][j - 1]][j - 1];
			minw[i][j] = min(minw[i][j - 1], minw[go[i][j - 1]][j - 1]);
			go[i][j] = go[go[i][j - 1]][j - 1];
		}
	}
	for(int i = 0; i < n; i++){
		int v = i;
		LL sm = 0,
		   mn = 2000LL * 1000 * 1000;
		mn *= mn;
		for(int j = 0; j < maxl; j++)
			if((k >> j) & 1LL){
				sm += sumw[v][j];
				smin(mn, minw[v][j]);
				v = go[v][j];
			}
		cout << sm << ' ' << mn << '\n';
	}
	return 0;
}