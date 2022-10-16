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

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;
const int P = 1e7 + 19;
const int OFF = (1 << 15);

inline int add(const int &A, const int &B){
	if(A + B >= MOD) return A + B - MOD;
	return A + B;
}

inline int mul(const int &A, const int &B){
	return (ll)A * B % MOD;
}

inline int sub(const int &A, const int &B){
	if(A - B < 0) return A - B + MOD;
	return A - B;
}

inline int pot(const int &A, int B){
	int cur = A, ret = 1;
	for(;B;B >>= 1){
		if(B & 1) ret = mul(ret, cur);
		cur = mul(cur, cur);
	}
	return ret;
}

inline int divv(const int &A, const int &B){
	return mul(A, pot(B, MOD - 2));
}

vector < vector < ll > > dp;
vector < int > ans;
vector < pii > v[2 * OFF];
int W, n, q, pre_pot[N], ispis[OFF], st[N], pos[N], un[N], sm[2 * OFF];
pii novi[N];

void dodaj(pii X){
	int v = X.X, w = X.Y;
	vector < ll > nw(W + 1, 0);
	int odg = 0;
	for(int i = 1;i <= W;i++){
		if((int)dp.size() > 0)
			nw[i] = dp.back()[i];
		if(i >= w)
			nw[i] = max(nw[i], ((int)dp.size() > 0 ? dp.back()[i - w] : 0) + v);
		odg = add(odg, mul(nw[i] % MOD, pre_pot[i - 1])); 
	}
	dp.PB(nw); ans.PB(odg);
}

void makni(int k){
	for(;k--;) dp.pop_back(), ans.pop_back();
}

void ubaci(int i,int a,int b,int lo,int hi, pii X){
	if(lo <= a && b <= hi){
		v[i].PB(X); return;
	}
	if(a > hi || b < lo) return;
	ubaci(2 * i, a, (a + b) / 2, lo, hi, X);
	ubaci(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, X);
}

void obradi(int i){
	if(!sm[i]) return;
	for(pii tmp : v[i]) dodaj(tmp);
	if(i < OFF){
		obradi(2 * i); obradi(2 * i + 1);
	}
	else if(ispis[i - OFF]){
		if(ans.size() > 0)
			printf("%d\n", ans.back());
		else
			printf("0\n");
	}
	makni((int)v[i].size());
}

int main(){
	pre_pot[0] = 1;
	for(int i = 1;i < N;i++)
		pre_pot[i] = mul(pre_pot[i - 1], P);
	scanf("%d%d", &n, &W);
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &novi[i].X, &novi[i].Y);
		st[i] = 0; un[i] = 1;
	}
	scanf("%d", &q); int cur = n + 1;
	for(int i = 0;i < q;i++){
		int ty; scanf("%d", &ty);
		if(ty == 3){
			ispis[i] = 1; 
			for(int ii = (OFF + i) ; ii ; ii /= 2)
				sm[ii]++;
		}
		else if(ty == 2){
			int x; scanf("%d", &x); un[x] = 0;
			ubaci(1, 0, OFF - 1, st[x], i, novi[x]);
		}
		else{
			st[cur] = i; un[cur] = 1;
			scanf("%d%d", &novi[cur].X, &novi[cur].Y);
			cur++;
		}
	}
	for(int i = 0;i < N;i++)
		if(un[i]) ubaci(1, 0, OFF - 1, st[i], OFF - 1, novi[i]);
	obradi(1);
	return 0;
}