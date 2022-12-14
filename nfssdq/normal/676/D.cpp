/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

typedef pair<pair<int,int>,int> pp;
queue < pp > Q;
int nxt[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int dis[1001][1001][17], ar[1001][1001][4];
char ss[1002][1002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	REP(i, n) cin >> ss[i];
	
	REP(i, n){
		REP(j, m){
			if(ss[i][j] == '+'){
				REP(k, 4) ar[i][j][k] = 1;
			} else if(ss[i][j] == '-'){
				ar[i][j][0] = ar[i][j][2] = 1;
			} else if(ss[i][j] == '|'){
				ar[i][j][1] = ar[i][j][3] = 1;
			} 
			else if(ss[i][j] == '<') ar[i][j][0] = 1;
			else if(ss[i][j] == '^') ar[i][j][1] = 1;
			else if(ss[i][j] == '>') ar[i][j][2] = 1;
			else if(ss[i][j] == 'v') ar[i][j][3] = 1;
			else if(ss[i][j] == 'L') ar[i][j][1] = ar[i][j][2] = ar[i][j][3] = 1;
			else if(ss[i][j] == 'U') ar[i][j][0] = ar[i][j][2] = ar[i][j][3] = 1;
			else if(ss[i][j] == 'R') ar[i][j][0] = ar[i][j][1] = ar[i][j][3] = 1;
			else if(ss[i][j] == 'D') ar[i][j][0] = ar[i][j][1] = ar[i][j][2] = 1;
		}
	}
	
	int x1, y1; cin >> x1 >> y1; x1--; y1--;
	setinf(dis);
	Q.push(mp(mp(x1, y1), 0));
	dis[x1][y1][0] = 0;
	
	while(!Q.empty()){
		pp p = Q.front(); Q.pop();
		//cout << p.xx.xx << " " << p.xx.yy << " " << p.yy << " " << dis[p.xx.xx][p.xx.yy][p.yy] << endl;
		REP(i, 4){
			int x = p.xx.xx + nxt[i][0];
			int y = p.xx.yy + nxt[i][1];
		
			if(x < 0 || x >= n || y < 0 || y >= m || ss[x][y] == '*') continue;
		
			int v = i;
			if(i < 2) v += 2;
			else v -= 2;
			
			if(!(ar[p.xx.xx][p.xx.yy][ (i - p.yy + 16) % 4 ] && ar[x][y][ (v - p.yy + 16) % 4 ])) continue;
			if(dis[x][y][p.yy] > 1 + dis[p.xx.xx][p.xx.yy][p.yy]){
				dis[x][y][p.yy] = 1 + dis[p.xx.xx][p.xx.yy][p.yy];
				Q.push(mp(mp(x,y), p.yy));
			}
		}
		
		if(dis[p.xx.xx][p.xx.yy][(p.yy+1)%16] > 1 + dis[p.xx.xx][p.xx.yy][p.yy]){
			dis[p.xx.xx][p.xx.yy][(p.yy+1)%16] = 1 + dis[p.xx.xx][p.xx.yy][p.yy];
			Q.push(mp(p.xx, (p.yy+1)%16));	
		}
	}
	
	int x2, y2; cin >> x2 >> y2; x2--; y2--;
	int res = mod;
	//cout << dis[x1][y1][3] << endl;
	REP(i, 16){
		res = min(res, dis[x2][y2][i]); 
	}
	
	if(res > 100000000) cout << -1 << endl;
	else cout << res << endl;
}