#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; // 998244353
const int LOG = 20;
const int OFF = (1 << 20);

set < int > S;
int n, q, bol[N], zdr[N];

int naj[N];

void ocisti(int l, int r){
	vector < pii > ubac;
	auto it = S.lower_bound(l);
	for(;it != S.end() && *it <= r; it = S.erase(it)){
		if(naj[*it] != INF) ubac.PB({*it, naj[*it]});
		zdr[*it] = 1;
	}
	for(pii tmp : ubac){
		int nw = *S.lower_bound(tmp.X);
		naj[nw] = min(naj[nw], *(--S.upper_bound(tmp.Y)));
	}
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) S.insert(i), naj[i] = INF;
	for(;q--;){
		int ty; scanf("%d", &ty);
		if(!ty){
			int l, r, x; scanf("%d%d%d", &l, &r, &x);
			if(!x) ocisti(l, r);
			else{
				l = *S.lower_bound(l);  r = *(--S.upper_bound(r));
				naj[l] = min(naj[l], r);
			}
		}
		else{
			int x; scanf("%d", &x);
			if(!zdr[x] && naj[x] < INF)
				naj[x] = *(--S.upper_bound(naj[x]));
			if(zdr[x]) printf("NO\n");
			else if(naj[x] == x) printf("YES\n");
			else printf("N/A\n");
		}
	}
	return 0;
}