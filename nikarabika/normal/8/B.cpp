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

const int maxn = 300;
int pos[maxn][maxn];
int dx[128], dy[128];
int n;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	dx['U'] = -1;
	dx['D'] = +1;
	dy['L'] = -1;
	dy['R'] = +1;
	cin >> s;
	s = '#' + s;
	memset(pos, -1, sizeof pos);
	pos[150][150] = 0;
	int xp = 150, yp = 150;
	for(int i = 1; i < sz(s); i++){
		xp += dx[s[i]];
		yp += dy[s[i]];
		if(~pos[xp][yp]){
			cout << "BUG\n";
			return 0;
		}
		pos[xp][yp] = i;
	}
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			if(~pos[i][j])
				for(auto c : "LURD"){
					int x = i + dx[c];
					int y = j + dy[c];
					if(pos[x][y] > pos[i][j] + 1){
						cout << "BUG\n";
						return 0;
					}
				}
	cout << "OK\n";
	return 0;
}