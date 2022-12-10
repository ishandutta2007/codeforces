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

const int maxn = 1000 + 85 - 69;
LL row[maxn],
   col[maxn],
   n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			LL val;
			cin >> val;
			row[i] += val;
			col[j] += val;
		}
	int xpos, ypos;
	LL mn = 1e18;
	for(int i = 0; i <= m; i++){
		LL val = 0;
		for(int j = 0; j < m; j++){
			LL dis = abs(4 * i - (4 * j + 2));
			val += dis * dis * col[j];
		}
		if(val < mn){
			mn = val;
			xpos = i;
		}
	}
	LL ans = mn;
	mn = 1e18;
	for(int i = 0; i <= n; i++){
		LL val = 0;
		for(int j = 0; j < n; j++){
			LL dis = abs(4 * i - (4 * j + 2));
			val += dis * dis * row[j];
		}
		if(val < mn){
			mn = val;
			ypos = i;
		}
	}
	cout << ans + mn << endl;
	cout << ypos << ' ' << xpos << endl;
	return 0;
}