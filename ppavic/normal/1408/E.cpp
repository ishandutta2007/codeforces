#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pii pt;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << LOG);

int cst[N], n, m, par[N];
ll uk = 0;

bool cmp(pii A, pii B){
	return cst[A.X] + cst[A.Y] > cst[B.X] + cst[B.Y];
}

int pr(int x){
	if(x == par[x]) return x;
	return par[x] = pr(par[x]);
}

vector < pii > edg;

int main(){
	scanf("%d%d", &m, &n);
	for(int i = 0;i < m;i++)
		scanf("%d", cst + i), par[i] = i;
	for(int i = 0;i < n;i++)
		scanf("%d", cst + m + i), par[m + i] = m + i;
	for(int i = 0;i < m;i++){
		int sz; scanf("%d", &sz);
		for(;sz--;){
			int x; scanf("%d", &x);
			x = (x - 1 + m);
			edg.PB({x, i});
			uk += cst[x] + cst[i];
		}
	}
	sort(edg.begin(), edg.end(), cmp);
	for(int i = 0;i < (int)edg.size();i++){
		if(pr(edg[i].X) != pr(edg[i].Y))
			uk -= cst[edg[i].X] + cst[edg[i].Y];
		par[pr(edg[i].X)] = pr(edg[i].Y);
	}
	printf("%lld\n", uk);
	return 0;
}