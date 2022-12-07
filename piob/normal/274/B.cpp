#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long LL;

int n, a, b;
vector<int> E[100010];
int P[100010];
LL V[100010];

PLL dfs(int u){
    PLL r, m = PLL(0,0);
    FE(v,E[u])
        if(P[u] != *v){
            P[*v] = u;
            r = dfs(*v);
            m.x = max(r.x, m.x);
            m.y = max(r.y, m.y);
        }
    V[u] += m.x - m.y;
    if(V[u] > 0) m.y += V[u];
    if(V[u] < 0) m.x -= V[u];
    return m;
}

int main(){
    cin >> n;
    FWD(i,0,n-1){
        cin >> a >> b;
        E[a].pb(b);
        E[b].pb(a);
    }
    FWD(i,1,n+1) cin >> V[i];
    P[1] = 0;
    PLL r = dfs(1);
    cout << (r.x + r.y) << endl;
    return 0;
}