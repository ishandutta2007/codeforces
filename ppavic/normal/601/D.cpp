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
 
const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int LOG = 20;
const int ALP = 30;
const int BASE1 = 2861;
const int BASE2 = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;
 
inline int add2(const int &A, const int &B, const int &MOD){
	if(A + B >= MOD) return A + B - MOD;
	return A + B;
}
 
inline int mul2(const int &A, const int &B, const int &MOD){
	return (ll)A * B % MOD;
}
 
inline int sub2(const int &A, const int &B, const int &MOD){
	if(A - B < 0) return A - B + MOD;
	return A - B;
}
 
inline int pot2(const int &A, int B, const int &MOD){
	int cur = A, ret = 1;
	for(;B;B >>= 1){
		if(B & 1) ret = mul2(ret, cur, MOD);
		cur = mul2(cur, cur, MOD);
	}
	return ret;
}

inline int divv2(const int &A, const int &B, const int &MOD){
	return mul2(A, pot2(B, MOD - 2, MOD), MOD);
}

inline pii add(const pii &A, const pii &B){
	return {add2(A.X, B.X, MOD1), add2(A.Y, B.Y, MOD2)};
}

inline pii sub(const pii &A, const pii &B){
	return {sub2(A.X, B.X, MOD1), sub2(A.Y, B.Y, MOD2)};
}

inline pii mul(const pii &A, const pii &B){
	return {mul2(A.X, B.X, MOD1), mul2(A.Y, B.Y, MOD2)};
}

inline pii divv(const pii &A, const pii &B){
	return {divv2(A.X, B.X, MOD1), divv2(A.Y, B.Y, MOD2)};
}
 
 
pii kof_mul[N], kof_add[N];
int n, c[N];
set < pii > S[N]; char s[N];
vector < int > v[N];
int ans, cnt;
 
 
pii osnovni(pii x,int i){
	return add(mul(x, kof_mul[i]), kof_add[i]);
}
 
pii transform(pii x,int i){
	return divv(sub(x, kof_add[i]), kof_mul[i]);
}
 
void dodaj(int i,pii x){
	kof_add[i] = add(kof_add[i], x);
}
 
void pomnozi(int i,pii x){
	kof_add[i] = mul(kof_add[i], x);
	kof_mul[i] = mul(kof_mul[i], x);
}
 
void zamijeni(int i,int j){
	swap(S[i], S[j]), swap(kof_add[i], kof_add[j]);
	swap(kof_mul[i], kof_mul[j]);
}
 
void rijesi(int x,int lst){
	S[x].insert({0, 0}); kof_mul[x] = {1, 1};
	for(int y : v[x]){
		if(y == lst) continue;
		rijesi(y, x);
		if(S[y].size() > S[x].size())
			zamijeni(x, y);
		for(pii tmp : S[y])
			S[x].insert(transform(osnovni(tmp , y), x));
	}
	pomnozi(x, {BASE1, BASE2});
	dodaj(x, {s[x], s[x]});
	int ja = (int)S[x].size() + c[x];
	if(ja > ans) ans = ja, cnt = 0;
	if(ja == ans) cnt++;
}
 
int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", c + i);
	for(int i = 1;i <= n;i++) scanf(" %c", s + i);
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB(y), v[y].PB(x);
	}
	rijesi(1, 1);
	printf("%d\n%d\n", ans, cnt);
	return 0;
}