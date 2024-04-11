//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 1000;
const LL Mod = 1e9 + 7;
LL c[maxn][maxn];
int n, m, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	c[0][0] = 1;
	for(int i = 1; i < maxn; i++){
		c[i][0] = 1;
		for(int j = 1; j < maxn; j++){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			if(c[i][j] >= Mod)
				c[i][j] -= Mod;
		}
	}
	int n, m, k;
	cin >> n >> m >> k;
	if(n > m) swap(n, m);
	if(2 * k + 1 > n){
		cout << 0 << endl;
		return 0;
	}
	cout << (c[n - 1][2 * k] * c[m - 1][2 * k]) % Mod;
	return 0;
}