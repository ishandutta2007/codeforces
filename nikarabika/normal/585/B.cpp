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

const int maxn = 100 + 85 - 69;
bool mark[3][maxn],
	 forb[3][maxn];
int n, k;

bool go(int r, int c){
	if(c >= n)
		return true;
	mark[r][c] = true;
	if(forb[r][c + 1])
		return false;
	if(!mark[r][c + 3] and !forb[r][c + 1] and !forb[r][c + 2] and !forb[r][c + 3] and go(r, c + 3))
		return true;
	if(r and !forb[r - 1][c + 1] and !forb[r - 1][c + 2] and !forb[r - 1][c + 3] and !mark[r - 1][c + 3] and go(r - 1, c + 3))
		return true;
	if(r != 2 and !forb[r + 1][c + 1] and !forb[r + 1][c + 2] and !forb[r + 1][c + 3] and !mark[r + 1][c + 3] and go(r + 1, c + 3))
		return true;
	return false;
}

void solve(void){
	memset(forb, false, sizeof forb);
	memset(mark, false, sizeof mark);
	cin >> n >> k;
	int source;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < n; j++){
			char x;
			cin >> x;
			if(x == '.')
				continue;
			if(x == 's')
				source = i;
			else
				forb[i][j] = true;
		}
	if(go(source, 0))
		cout << "YES\n";
	else
		cout << "NO\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}