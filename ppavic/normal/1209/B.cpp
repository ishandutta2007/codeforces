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

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int n, S[N], aa[N], bb[N];

int tren(int a,int b,int x){
	if(x < b) return 0;
	x -= b;
	return (x / a + 1) % 2;
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		char c; scanf(" %c", &c);
		S[i] = (c == '1');
	}
	for(int i = 0;i < n;i++) scanf("%d%d", aa + i, bb + i);
	int sol = 0;
	for(int i = 0;i < 1e4;i++){
		int cur = 0;
		for(int j = 0;j < n;j++){
			cur += S[j] ^ tren(aa[j], bb[j], i);
		}
		sol = max(sol, cur);
	}
	printf("%d\n", sol);
	return 0;
}