#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iostream>

#define X first
#define Y second
#define PB push_back
#define TRACE(x) printf("%s = %d\n", #x, x);

/*

           _   _ _____ __  __          _      _      _      _      
     /\   | \ | |_   _|  \/  |   /\   | |    | |    | |    | |     
    /  \  |  \| | | | | \  / |  /  \  | |    | |    | |    | |     
   / /\ \ | . ` | | | | |\/| | / /\ \ | |    | |    | |    | |     
  / ____ \| |\  |_| |_| |  | |/ ____ \| |____| |____| |____| |____ 
 /_/    \_\_| \_|_____|_|  |_/_/    \_\______|______|______|______|
                                                                   
                                                                   
                          ..,co88oc.oo8888cc,..
  o8o.               ..,o8889689ooo888o"88888888oooc..
.88888             .o888896888".88888888o'?888888888889ooo....
a888P          ..c6888969""..,"o888888888o.?8888888888"".ooo8888oo.
088P        ..atc88889"".,oo8o.86888888888o 88988889",o888888888888.
888t  ...coo688889"'.ooo88o88b.'86988988889 8688888'o8888896989^888o
 888888888888"..ooo888968888888  "9o688888' "888988 8888868888'o88888
  ""G8889""'ooo888888888888889 .d8o9889""'   "8688o."88888988"o888888o .
           o8888'""""""""""'   o8688"          88868. 888888.68988888"o8o.
           88888o.              "8888ooo.        '8888. 88888.8898888o"888o.
           "888888'               "888888'          '""8o"8888.8869888oo8888o .
      . :.:::::::::::.: .     . :.::::::::.: .   . : ::.:."8888 "888888888888o
                                                        :..8888,. "88888888888.
                                                        .:o888.o8o.  "866o9888o
                                                         :888.o8888.  "88."89".
                                                        . 89  888888    "88":.
                    atc                                 :.     '8888o
                                                         .       "8888..
                                                                   888888o.
                                                                    "888889,
                                                             . : :.:::::::.: :.

------------------------------------------------
Thank you for visiting https://asciiart.website/
This ASCII pic can be found at
https://asciiart.website/index.php?art=animals/cats


*/

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef vector < pii > vp;
typedef set < int > si;
typedef set < ll > sl;
typedef set < pii > sp;
typedef pair < ld, ld > pt;

const int N = 410;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int mat[N][N], n, m;
int dis[N][N][2];


void bfs(){
	queue < int > Qx, Qy, Qfl;
	Qx.push(1), Qy.push(1), Qfl.push(0);
	dis[1][1][0] = 1;
	for(;!Qx.empty();){
		int x = Qx.front(), y = Qy.front(), fl = Qfl.front();
		Qx.pop(), Qy.pop(), Qfl.pop();
		//printf("%d %d %d => %d\n", x, y, fl, dis[x][y][fl]);
		for(int i = 1;i <= n;i++){
			if(mat[x][i] && !fl && !dis[i][y][!fl]){
				dis[i][y][!fl] = dis[x][y][fl] + 1;
				Qx.push(i), Qy.push(y), Qfl.push(!fl);
			}
			if((!mat[y][i] || y == i) && fl && !dis[x][i][!fl] && (x != i || x == n)){
				dis[x][i][!fl] = dis[x][y][fl];
				Qx.push(x), Qy.push(i), Qfl.push(!fl);
			}
		}
	}
}


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) mat[i][i] = 1;
	for(int i = 0;i < m;i++){
		int x, y; scanf("%d%d", &x, &y);
		mat[x][y] = 1, mat[y][x] = 1;
	}
	bfs();
	printf("%d\n", dis[n][n][0] - 1);
	return 0;
}