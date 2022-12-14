#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAXN = 5005;

char s[MAXN];
char d[MAXN][MAXN];
string ans;

struct Node
{
    int term;
    int sum;
    int next[2];
};

Node nodes[MAXN * MAXN];

void dfs(int v)
{
    nodes[v].sum = nodes[v].term;
    forn (j, 2)
    {
        int to = nodes[v].next[j];
        if (to != 0)
        {
            dfs(to);
            nodes[v].sum += nodes[to].sum;
        }
    }
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    gets(s);
    int k;
    scanf("%d", &k);
    int n = strlen(s);
    forn (i, n)
    {
        for (int j = i; j >= 0; j -= 2)
        {
            if (s[j] != s[2 * i + 1 - j])
                break;
            d[j][2 * i + 1 - j] = 1;
        }
        for (int j = i - 1; j >= 0; j -= 2)
        {
            if (s[j] != s[2 * i + 1 - j])
                break;
            d[j][2 * i + 1 - j] = 1;
        }
        for (int j = i; j >= 0; j -= 2)
        {
            if (s[j] != s[2 * i - j])
                break;
            d[j][2 * i - j] = 1;
        }
        for (int j = i - 1; j >= 0; j -= 2)
        {
            if (s[j] != s[2 * i - j])
                break;
            d[j][2 * i - j] = 1;
        }
    }
    int cnt = 2;
    forn (i, n)
    {
        int curV = 1;
        forab (j, i, n)
        {
            int &nex = nodes[curV].next[s[j] - 'a'];
            if (nex == 0)
                nex = cnt++;
            curV = nex;
            if (d[i][j])
                nodes[curV].term++;
        }
    }
    dfs(1);
    int curV = 1;
    while (k > 0)
    {
        k -= nodes[curV].term;
        if (k <= 0)
            break;
        if (nodes[curV].next[0] == 0)
        {
            if (nodes[curV].next[1] == 0)
                break;
            curV = nodes[curV].next[1];
            ans += 'b';
            continue;
        }
        if (k <= nodes[nodes[curV].next[0]].sum)
            curV = nodes[curV].next[0], ans += 'a';
        else
            k -= nodes[nodes[curV].next[0]].sum, curV = nodes[curV].next[1], ans += 'b';
    }
    cout << ans << endl;
    return 0;
}