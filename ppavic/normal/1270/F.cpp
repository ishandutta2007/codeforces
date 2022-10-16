#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>

#define X first
#define Y second
#define PB push_back

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
using namespace __gnu_pbds;

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

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;
const int K = 100;

char s[N];
int p[N], ima[2 * N], n;
//gp_hash_table < int , int > mp;
vector < int > jed;

ll count(int x){
	ll ret = 0;
	vector < int > tmp;
	for(int i = 0;i <= n;i++){
		tmp.PB(x * p[i] - i);
	}
	sort(tmp.begin(), tmp.end());
	for(int i = 0;i <= n;){
		int j = i;
		while(j <= n && tmp[j] == tmp[i]) j++;
		ret += (ll)(j - i) * (ll)(j - i - 1) / 2LL;
		i = j;	
	}
	return ret;
}

int main(){
	scanf("%s", s); n = strlen(s);
	jed.PB(0);
	for(int i = 1;i <= n;i++){
		p[i] = p[i - 1] + s[i - 1] - '0'; 
		if(s[i - 1] == '1') jed.PB(i);
	}
	if((int)jed.size() == 0){
		printf("0\n"); return 0;
	}
	ll sol = 0;
	for(int i = 1;i <= K;i++)
		sol += count(i);
	int j = 0;
	for(int i = 1;i <= n;i++){
		while(p[i] - p[jed[j]] > n / K + 5) j++;
		for(int j2 = j;j2 < (int)jed.size() && jed[j2] < i;j2++){
			int br = p[i] - p[jed[j2]];
			if(br == 0) continue;
			int mks = i - jed[j2];
			int mi = 1;
			if(j2 + 1 < (int)jed.size() && jed[j2 + 1] <= i){
				mi = i - jed[j2 + 1] + 1;
			}
			mks /= br;
			mi = max((mi - 1) / br, K);
			sol += max(mks - mi, 0);
		}
	}
	printf("%lld\n", sol);
	return 0;
}