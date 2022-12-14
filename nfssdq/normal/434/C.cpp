/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


struct trie
{
    int next[21],fail,cnt;
    void clear(){ memset(next, -1, sizeof next); fail=cnt=0; }
};

trie node[210];

int qs[210][210], len[210], val1[210];

int q,n,m;

void init()
{
    set0(node[0].next);
    node[0].fail=0;

    n=1;
}

void insert(int x)
{
    int pos=0;
    for(int i=0;i<len[x];i++)
    {
        if(node[pos].next[qs[x][i]]<=0)
        {
            node[n].clear();
            node[pos].next[qs[x][i]]=n++;
        }
        pos=node[pos].next[qs[x][i]];
    }
    node[pos].cnt += val1[x];
}

void get_failure()
{
    queue<int>q;

    REP(i,m)
        if(node[0].next[i])
        {
            node[node[0].next[i]].fail=0;
            q.push(node[0].next[i]);
        }

    while(!q.empty())
    {
        int u,v;
        u=q.front();
        q.pop();

        REP(i,m)
            if(node[u].next[i]!=-1)
            {
                v=node[u].next[i];
                q.push(v);
                int x=node[u].fail;
                while(node[x].next[i]==-1) x=node[x].fail;
                node[v].fail=node[x].next[i];
            }
    }
}
int dp[201][201][501][2][2];
int ar[2][210], val[210];
int go(int digit, int pos, int K, int d, int z){
    if(K < 0) return 0;
    if(digit < 0) return z;
    int &ret = dp[digit][pos][K][d][z];
    if(ret != -1) return ret;
    ret = 0;
    REP(i, m){
        if(d == 0 && i > val[digit]) break;

        int tp = pos;
        while(node[tp].next[i] == -1) tp = node[tp].fail;
        tp = node[tp].next[i];

        int nk = K, x = tp;
        while(x > 0){
            nk -= node[x].cnt;
            x = node[x].fail;
        }

        int nd = d; if(i < val[digit]) nd = 1;

        int nz = z; if(i != 0) nz = 1;

        if(nz == 0) {
            nk = K;
            tp = pos;
        }

        ret = (ret + go(digit - 1, tp, nk, nd, nz)) % mod;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> z >> m >> a;
    cin >> b; REP(i, b) cin >> ar[0][i];
    cin >> c; REP(i, c) cin >> ar[1][i];
    reverse(ar[0], ar[0] + b);
    reverse(ar[1], ar[1] + c);
    init();
    REP(i, z){
        cin >> len[i];
        REP(j, len[i]) cin >> qs[i][j];
        cin >> val1[i];
        insert(i);
    }
    get_failure();
    d = 0;
    while(ar[0][d] == 0){
        ar[0][d++] = m - 1;
    }
    ar[0][d]--;
    d = 0;
    REP(i, b) val[i] = ar[0][i];
    memset(dp, -1, sizeof dp);
    d = (d - go(b - 1, 0, a, 0, 0) + mod) % mod;
    REP(i, c) val[i] = ar[1][i];
    memset(dp, -1, sizeof dp);
    d = (d + go(c - 1, 0, a, 0, 0)) % mod;
    cout << d << endl;
}