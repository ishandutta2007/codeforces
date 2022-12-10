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

const int maxn = 85 - 69 + 85;
int n, m;
bool mark[maxn][2],
	 filled[maxn][maxn][3][3];
int GN[maxn][maxn][3][3];

int gn(int st, int en, int ty1, int ty2){
	if(filled[st][en][ty1][ty2])
		return GN[st][en][ty1][ty2];
	filled[st][en][ty1][ty2] = true;
	bool gns[2 * maxn];
	memset(gns, false, sizeof gns);
	for(int i = st + bool(ty1 & 2); i <= en - bool(ty2 & 2); i++)
		if(!mark[i][0]){
			int val = gn(st, i - 1, ty1, 1) ^ gn(i + 1, en, 1, ty2);
			if(val < 2 * maxn)
				gns[val] = true;
		}
	for(int i = st + (ty1 & 1); i <= en - (ty2 & 1); i++)
		if(!mark[i][1]){
			int val = gn(st, i - 1, ty1, 2) ^ gn(i + 1, en, 2, ty2);
			if(val < 2 * maxn)
				gns[val] = true;
		}
	for(int i = 0; i < 2 * maxn; i++)
		if(!gns[i])
			return GN[st][en][ty1][ty2] = i;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		mark[fi][se] = true;
		mark[fi][1 - se] = true;
		if(fi - 1 >= 0)
			mark[fi - 1][1 - se] = true;
		if(fi + 1 < n)
			mark[fi + 1][1 - se] = true;
	}
	if(gn(0, n - 1, 0, 0))
		cout << "WIN";
	else
		cout << "LOSE";
	return 0;
}