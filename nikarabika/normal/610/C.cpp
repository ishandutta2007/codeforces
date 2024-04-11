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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

int n;
bool ans[2000][2000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ans[0][0] = 0;
	for(int lev = 1; lev <= n; lev++){
		int shif = 1 << (lev - 1);
		for(int i = 0; i < shif; i++)
			for(int j = shif; j < shif * 2; j++)
				ans[i][j] = ans[i][j - shif];
		for(int i = shif; i < 2 * shif; i++)
			for(int j = 0; j < shif; j++)
				ans[i][j] = ans[i - shif][j];
		for(int i = shif; i < 2 * shif; i++)
			for(int j = shif; j < 2 * shif; j++)
				ans[i][j] = !ans[i - shif][j - shif];
	}
	for(int i = 0; i < (1 << n); i++, cout << endl)
		for(int j = 0; j < (1 << n); j++)
			cout << (ans[i][j] ? '+' : '*');
	return 0;
}