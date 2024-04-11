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

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int n, q, a[N], R[N], cnt[N];

int rijesi(int l,int r){
	int mx = 0; //printf("%d %d\n", l, r);
	for(int i = l;i <= r;i++) cnt[a[i]]++, mx = max(mx, cnt[a[i]]);
	for(int i = l;i <= r;i++) cnt[a[i]] = 0;
	return r - l + 1 - mx;

}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 0;i < n;i++)
		scanf("%d", a + i), R[a[i]] = i;
	int sol = 0;
	for(int i = 0;i < n;i++){
		int l = i, r = R[a[i]];
		for(;i < r;i++, r = max(r, R[a[i]]));
		sol += rijesi(l, i);
	}
	printf("%d\n", sol);
	return 0;
}