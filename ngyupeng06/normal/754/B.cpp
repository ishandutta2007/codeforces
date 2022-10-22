#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef long double ld;
typedef pair<ld,li> pdi;
typedef pair<li,li> pll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define inf 2e9

li n, m, a, b, c, d, i, j, k, l, p, q, r, t, ans, sum, cmax, cmin, dx[8]={0,1,0,-1,1,1,-1,-1}, dy[8]={1,0,-1,0,-1,1,-1,1};
deque<pll> dq;
char arr[5][5];
bool good;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (i=0; i<4; i++){
		for (j=0; j<4; j++) cin >> arr[i][j];
	}
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			if (arr[i][j]!='x') continue;
			for (k=0; k<8; k++){
				a = j+dx[k];
				b = j+2*dx[k];
				c = i+dy[k];
				d = i+2*dy[k];
				if (a<0||b<0||c<0||d<0||a>=4||b>=4||c>=4||d>=4) continue;
				if (arr[c][a]=='x'&&arr[d][b]=='.') good = true;
				if (arr[c][a]=='.'&&arr[d][b]=='x') good = true;
			}
		}
	}
	if (good) cout << "YES";
	else cout << "NO";
}