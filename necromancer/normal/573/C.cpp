#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

VI Map[100000];

int dd[100000];

void dfs1(int u, int fa=-1) {
    dd[u] = 0;
    int c = 0;
    REP(i,Map[u].size()) {
        int v = Map[u][i];
        if(v == fa) continue;
        dfs1(v, u);
        dd[u] += dd[v];
        c++;
    }
    dd[u] = max(dd[u], 1);
    if(dd[u] == 2 && c == 1) dd[u] = 3;
}

int ok = 1;

void dfs2(int u, int d=0, int fa=-1) {
    int cnt = 0;
    if(d >= 3) cnt++;
    REP(i,Map[u].size()) {
        int v = Map[u][i];
        if(v == fa) continue;
        if(dd[v] >= 3) cnt++;
        int dx = max(d+dd[u]-dd[v], 1);
        if(dx == 2 && d == 2) dx = 3;
        dfs2(v, dx, u);
    }
    if(cnt >= 3) ok = 0;
}

int main()
{
#ifdef LOCAL
       //freopen("x.in","r",stdin);
       //freopen("x.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--; v--;
        Map[u].PB(v);
        Map[v].PB(u);
    }
    dfs1(0);
    dfs2(0);
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}