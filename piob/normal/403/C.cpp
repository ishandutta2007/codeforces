#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) a.erase(unique(ALL(a)), (a).end())
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

//int dx[] = {0,0,-1,1}; //,1,1,-1,-1}; //,0};
//int dy[] = {-1,1,0,0}; //,1,-1,1,-1}; //,0};

inline int gcd(int a, int b){ while(a&&b) a>b?a%=b:b%=a; return a+b; }

int n;

const int N = 10010;

namespace tar{
    vector<int> g[N];

    int t, in[N], low[N];
    vector<int> s;
    bool stacked[N];

    int scc[N], scc_n;
    bool value[N];

    void tarjan(int u) {
        low[u] = in[u] = t++;
        s.push_back(u);
        stacked[u] = true;
        for(int v : g[u]) {
            if (in[v] == -1) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (stacked[v]) low[u] = min(low[u], in[v]);
        }
        if (low[u]==in[u]) {
            for(;;) {
                int v = s.back(); s.pop_back();
                stacked[v] = false;
                scc[v] = scc_n;
                if (v==u) break;
            }
            scc_n++;
        }
    }

    bool solid() {
        REP(i,n) { in[i] = low[i] = -1; stacked[i] = false; }
        scc_n = t = 0;
        REP(i,n) if(in[i] == -1) tarjan(i);
        return scc_n == 1;
    }

}

int M[2010][2010];

int main(){
    scanf("%d", &n);
    FWD(i,0,n)
        FWD(j,0,n){
            scanf("%d", &M[i][j]);
            if(M[i][j] && i != j)
                tar::g[i].push_back(j);
        }
    if(tar::solid())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}