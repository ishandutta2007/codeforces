#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <map>

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

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;i++){
		string s; cin >> s;
		int sm = 0, br0 = 0, par = 0;
		for(char c : s){
			sm += c - '0';
			if(c == '0') br0++;
			if((c - '0') % 2 == 0) par++;
		}
		if(br0 > 0 && sm % 3 == 0 && par > 1){
			cout << "red\n";
		}
		else{
			cout << "cyan\n";
		}
	}
	return 0;
}