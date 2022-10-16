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

int n , m, k;
int koj[N], d[N], s[N], t[N], w[N];
ll dp[N][205];
vector < int > ub[N], izb[N];
set < pair < pii, int >  > S;

ll f(int c, int bl){
	if(bl > m) return (ll)INF * (ll)INF;
	if(c >= n + 1) return 0;
	if(dp[c][bl] != -1) return dp[c][bl];
	ll ret = f(c + 1, bl + 1);
	if(koj[c]) ret = min(ret, f(d[koj[c]] + 1, bl) + w[koj[c]]);
	else       ret = min(ret, f(c + 1, bl));
	//printf("%d %d = %lld %d\n", c, bl, ret, koj[c]);
	return dp[c][bl] = ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= k;i++){
		scanf("%d%d%d%d", s + i, t + i, d + i, w + i);
		ub[s[i]].PB(i);
		izb[t[i]].PB(i);
	}
	for(int i = 1;i <= n;i++){
		for(int x : ub[i])  S.insert({{w[x], d[x]}, x});
		if(!S.empty())
			koj[i] = S.rbegin() -> Y;
		//printf("%d\n", koj[i]);
		for(int x : izb[i]) S.erase({{w[x], d[x]}, x});
	}
	printf("%lld\n", f(1, 0));
	return 0;
}