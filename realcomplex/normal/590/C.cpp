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

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dd[3][N][N];
char conf[N][N];

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < N; i ++ ){
		for(int j = 0; j < N ; j ++ ){
			dd[0][i][j] = -1;
			dd[1][i][j] = -1;
			dd[2][i][j] = -1;
			conf[i][j] = '#';
		}
	}
	char s;
	for(int i = 1; i <= n;i ++ ){
		for(int j = 1; j <= m; j ++ ){
			cin >> conf[i][j];
			if(conf[i][j] != '#'){
				for(int x = 0; x < 3; x ++ )
					dd[x][i][j] = (int)1e8 + 9;
			}
		}
	}
	int ii, jj, ni, nj;
	int pr;
	for(int t = 0; t <= 2; t ++ ){
		deque<pii> cors;
		for(int i = 1; i <= n; i ++ ){
			for(int j = 1; j <= m;j ++ ){
				if(conf[i][j] == char(t + '1')){
					cors.push_back(mp(i, j));
					dd[t][i][j] = 0;
				}
			}
		}
		while(!cors.empty()){
			ii = cors.front().fi;
			jj = cors.front().se;
			cors.pop_front();
			for(int dir = 0; dir < 4; dir ++ ){
				ni = ii + d[dir][0];
				nj = jj + d[dir][1];
				if(conf[ni][nj] == '#')
					continue;
				pr = conf[ni][nj] == '.';
				if(dd[t][ii][jj] + pr < dd[t][ni][nj]){
					dd[t][ni][nj] = dd[t][ii][jj] + pr;
					if(pr == 0)
						cors.push_front(mp(ni, nj));
					else
						cors.push_back(mp(ni, nj));
				}
			}
		}
	}
	int ans = (int)1e9 + 9;
	int cur;
	for(int i = 1; i <= n; i ++ ){
		for(int j = 1; j <= m;j ++ ){
			if(conf[i][j] == '#')
				continue;
			cur = dd[0][i][j] + dd[1][i][j] + dd[2][i][j];
			if(conf[i][j] == '.')
				cur -= 2;
			ans = min(ans, cur);
		}
	}
	if(ans > n * m + 41214)
		ans = -1;
	cout << ans;
	return 0;
}