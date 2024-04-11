#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

#define FNAME "1"

const int MAXN = 6e5 + 5, INF = 1e9;

int n, m, s, t, used[MAXN], pr[MAXN], d[MAXN], q[2 * MAXN], first[MAXN], ex[MAXN];
vector <int> g[MAXN];
int x[MAXN], y[MAXN], was1[MAXN + 5], was2[MAXN + 5], num1[MAXN + 5], num2[MAXN + 5];

struct Edge
{
    int b, e, c, f, l;
    Edge(): b(0), e(0), c(0), f(0), l(0) {}
    Edge(int b, int e): b(b), e(e), c(0), f(0), l(0) {}
    Edge(int b, int e, int c, int l): b(b), e(e), c(c), f(0), l(l) {}
};

vector <Edge> edges;

int dfs(int v, int Min, int curPush)
{
    if (v == t)
        return Min;
    for (int i = first[v]; i < (int) g[v].size(); i++)
    {
        int to = edges[g[v][i]].e;
        if (d[to] != d[v] + 1 || edges[g[v][i]].c < edges[g[v][i]].f + curPush)
        {
            first[v]++;
            continue;
        }
        int l = dfs(to, min(Min, edges[g[v][i]].c - edges[g[v][i]].f), curPush);
        if (l == 0)
        {
            first[v]++;
            continue;
        }
        edges[g[v][i]].f += l;
        edges[g[v][i] ^ 1].f -= l;
        return l;
    }
    return 0;
}

void addEdge(int v, int u, int c, int l)
{
    edges.pb(Edge(v, u, c, l));
    g[v].pb(edges.size() - 1);        
    edges.pb(Edge(u, v, 0, l));
    g[u].pb(edges.size() - 1);      
}
              
int main() 
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        was1[x[i]]++;
        was2[y[i]]++;
    }
    int cur = 1;
    int S = cur++;

    for (int i = 0; i < MAXN; i++)
        if (was1[i] > 0)
            num1[i] = cur++;
    for (int i = 0; i < MAXN; i++)
        if (was2[i] > 0)
            num2[i] = cur++;
    int T = cur++;

    for (int i = 0; i < N; i++)
        addEdge(num1[x[i]], num2[y[i]], 1, 0);
    for (int i = 0; i < MAXN; i++)
        if (was1[i] > 0)
        {
            int l = was1[i] / 2, r = (was1[i] + 1) / 2;
            addEdge(S, num1[i], r - l, l);
            ex[S] += was1[i] / 2;
            ex[num1[i]] -= was1[i] / 2;
        }
    for (int i = 0; i < MAXN; i++)
        if (was2[i] > 0)
        {
            int l = was2[i] / 2, r = (was2[i] + 1) / 2;
            addEdge(num2[i], T, r - l, l);
            ex[num2[i]] += was2[i] / 2;
            ex[T] -= was2[i] / 2;
        }
    addEdge(T, S, 1e9, 0);
    
    n = cur - 1;
    m = edges.size() / 2;
    
    s = 0;
    t = n + 1;
    int mustFlowOut = 0, mustFlowIn = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ex[i] < 0)
        {
            addEdge(0, i, -ex[i], 0);
            mustFlowOut += abs(ex[i]);
        }
        if (ex[i] > 0)
        {
            addEdge(i, n + 1, ex[i], 0);
            mustFlowIn += abs(ex[i]);
        }
    }
    int flow = 0;
    n += 2;
    for (int j = 20; j >= 0; j--)
    {
        while(1)
        {
            int curPush = (1 << j);
            for (int i = 0; i < n; i++)
            {
                d[i] = INF;
                first[i] = 0;
            }
            int head = 0, tail = 0;
            q[tail++] = s;
            d[s] = 0;
            while (tail - head > 0)
            {
                int v = q[head++];
                for (int i = 0; i < (int) g[v].size(); i++)
                    if (d[edges[g[v][i]].e] > d[v] + 1 && edges[g[v][i]].c - edges[g[v][i]].f >= curPush)
                    {
                        d[edges[g[v][i]].e] = d[v] + 1;
                        q[tail++] = edges[g[v][i]].e;
                    }
            }
            if (d[t] != INF)
            {
                while (int curFlow = dfs(s, INF, curPush))
                    flow += curFlow;                        
            }
            else
                break;
        }
    }
    for (int i = 0; i < 2 * N; i += 2)
    {
        if (edges[i].f == 1)
            printf("b");
        else
            printf("r");    
    } 
    return 0;
}