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

const int maxn = 2000;
bool mark[maxn][maxn];
queue<pii> q;
int n, m, k;
int dx[4] = {-1, -0, +0, +1},
	dy[4] = {-0, -1, +1, +0};

bool valid(int x, int y){
	return x >= 0 and x < n
		and y >= 0 and y < m
		and !mark[x][y];
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> m
		>> k;
	for(int i = 0; i < k; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		q.push(MP(fi, se));
		mark[fi][se] = true;
	}
	while(sz(q)){
		int x = q.front().L,
			y = q.front().R;
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i],
				yy = y + dy[i];
			if(valid(xx, yy))
				mark[xx][yy] = true, q.push(MP(xx, yy));
		}
		if(sz(q) == 0){
			cout << x + 1 << ' ' << y + 1 << endl;
			return 0;
		}
	}
	return 0;
}