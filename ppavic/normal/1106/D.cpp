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

const int N = 1e6 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

set < int > S;
int bio[N], n, m;
vector < int > v[N], ans;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB(y), v[y].PB(x);
	}
	S.insert(1); bio[1] = 1;
	for(;!S.empty();){
		int cur = *S.begin(); 
		S.erase(S.begin());
		ans.PB(cur);
		for(int nxt : v[cur]){
			if(bio[nxt]) continue;
			bio[nxt] = 1;
			S.insert(nxt);
		}
	}
	for(int x : ans) printf("%d ", x);
	printf("\n");
	return 0;
}