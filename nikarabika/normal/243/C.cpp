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

const int maxn = 2000 + 85 - 69,
	  maxnn = maxn * maxn;
vector<pii> veca[maxn],
	veco[maxn],
	tmp;
pii pos[maxn];
vector<int> xall, yall;
bool mark[maxn][maxn];
int n, xpos, ypos;
int mp[256];
int dx[4] = {-1, -0, +0, +1},
	dy[4] = {-0, -1, +1, +0};
char dir[maxn];
int len[maxn];
const LL Inf = 1.5e9;
LL ans;

bool valid(int x, int y){
	if(x < 0 or x >= sz(xall) - 1 or y < 0 or y >= sz(yall) - 1 or mark[x][y]) return false;
	//int id = lower_bound(all(veca[x]), MP(y, 0)) - veca[x].begin();
	//if(id != sz(veca[x]) and veca[x][id].R <= y) return false;
	//id = lower_bound(all(veco[y]), MP(x, 0)) - veco[y].begin();
	//if(id != sz(veco[y]) and veco[y][id].R <= x) return false;
	return true;
}

void dfs(int x, int y){
	ans -= 1LL * (xall[x + 1] - xall[x]) * (yall[y + 1] - yall[y]);
	mark[x][y] = true;
	for(int i = 0; i < 4; i++){
		int xx = x + dx[i],
			yy = y + dy[i];
		if(valid(xx, yy))
			dfs(xx, yy);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ans = 4 * Inf * Inf;
	mp['L'] = 0;
	mp['D'] = 1;
	mp['U'] = 2;
	mp['R'] = 3;
	tmp.reserve(1 << 12);
	cin >> n;
	xall.PB(-Inf);
	xall.PB(+Inf);
	yall.PB(-Inf);
	yall.PB(+Inf);
	xall.PB(xpos);
	xall.PB(xpos + 1);
	yall.PB(ypos);
	yall.PB(ypos + 1);
	for(int i = 0; i < n; i++){
		cin >> dir[i] >> len[i];
		xpos += dx[mp[dir[i]]] * len[i];
		ypos += dy[mp[dir[i]]] * len[i];
		pos[i + 1] = {xpos, ypos};
		xall.PB(xpos);
		xall.PB(xpos + 1);
		yall.PB(ypos);
		yall.PB(ypos + 1);
	}
	sort(all(xall));
	sort(all(yall));
	xall.resize(unique(all(xall)) - xall.begin());
	yall.resize(unique(all(yall)) - yall.begin());
	for(int i = 0; i <= n; i++){
		pos[i].L = lower_bound(all(xall), pos[i].L) - xall.begin();
		pos[i].R = lower_bound(all(yall), pos[i].R) - yall.begin();
		if(!i) continue;
		if(pos[i].L == pos[i - 1].L){
			int st = min(pos[i].R, pos[i - 1].R),
				en = max(pos[i].R, pos[i - 1].R);
			for(int j = st; j <= en; j++)
				mark[pos[i].L][j] = true;
		}
		else{
			int st = min(pos[i].L, pos[i - 1].L),
				en = max(pos[i].L, pos[i - 1].L);
			for(int j = st; j <= en; j++)
				mark[j][pos[i].R] = true;
		}
	}
	/*for(int i = 0; i < maxn; i++){
		sort(all(veca[maxn]));
		tmp.clear();
		for(auto seg : veca[i]){
			while(sz(tmp) and tmp.back().L >= seg.R){
				smin(seg.R, tmp.back().R);
				tmp.pop_back();
			}
			tmp.push_back(seg);
		}
		veca[i] = tmp;
		sort(all(veco[maxn]));
		tmp.clear();
		for(auto seg : veco[i]){
			while(sz(tmp) and tmp.back().L >= seg.R){
				smin(seg.R, tmp.back().R);
				tmp.pop_back();
			}
			tmp.push_back(seg);
		}
		veco[i] = tmp;
	}*/
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}