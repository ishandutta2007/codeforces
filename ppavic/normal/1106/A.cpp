#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

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

const int N = 505;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int n, m;
char s[N][N];

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			scanf(" %c", &s[i][j]);
	int sol = 0;
	for(int i = 1;i + 1 < n;i++){
		for(int j = 1;j + 1 < n;j++){
			sol += (s[i][j] == 'X' && s[i + 1][j + 1] == 'X' && s[i + 1][j - 1] == 'X' && s[i - 1][j + 1] == 'X' && s[i - 1][j - 1] == 'X');
		}
		
	}
	printf("%d\n", sol);
	return 0;
}