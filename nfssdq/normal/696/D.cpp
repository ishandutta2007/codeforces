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
#define mod        1000000009ll
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








#define MX 210
LL mul_res[MX][MX];
void multiply(LL a[][MX], LL b[][MX]){
    REP(i, MX) REP(j, MX) mul_res[i][j] = -2ll*mod*mod;
    for(int i = 0; i < MX; i++){
        for(int j = 0; j < MX; j++){
            for(int k = 0; k < MX; k++){
                mul_res[i][j] = max(mul_res[i][j], a[i][k] + b[k][j]);
        	}
        }
    }
}


LL big_res[MX][MX];
LL init[MX][MX];
void matrix_expo(LL N){
    if(N == 1){
        REP(i, MX) REP(j, MX) big_res[i][j] = -2ll*mod*mod;
        REP(i, MX) big_res[i][i] = 0;
        return;
    }
    if(N % 2 == 0){
        matrix_expo(N / 2);
        multiply(big_res, big_res);
        REP(i, MX){
            REP(j, MX)big_res[i][j] = mul_res[i][j];
        }
        multiply(big_res, init);
        REP(i, MX) REP(j, MX) big_res[i][j] = mul_res[i][j];
    }
    else {
        matrix_expo(N - 1);
        multiply(big_res, init);
        REP(i, MX){
            REP(j, MX)big_res[i][j] = mul_res[i][j];
        }
    }
}






struct trie
{
    int next[27],fail,cnt;
    void clear(){ memset(next, -1, sizeof next); fail=cnt=0; }
};

trie node[210];

char qs[210][210];
int len[210], val1[210];

int q,n,m;

void ini()
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
        if(node[pos].next[qs[x][i]-'a']<=0)
        {
            node[n].clear();
            node[pos].next[qs[x][i]-'a']=n++;
        }
        pos=node[pos].next[qs[x][i]-'a'];
    }
    node[pos].cnt += val1[x];
}

void get_failure()
{
    queue<int>q;

    REP(i,26)
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

        REP(i,26)
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


int val[210][27], to[210][27];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; LL M; cin >> N >> M;
    REP(i, N) cin >> val1[i];
    ini();
    REP(i, N){
        cin >> qs[i];
        len[i] = strlen(qs[i]);
        insert(i);
    }
    get_failure();

    REP(i, n){
        REP(j, 26){
            int tp = i;
            while(node[tp].next[j] == -1) tp = node[tp].fail;
            tp = node[tp].next[j];

            int x = tp;
            while(x > 0){
                val[i][j] += node[x].cnt;
                x = node[x].fail;
            }

            to[i][j] = tp;
        }
    }

    REP(i, MX) REP(j, MX) init[i][j] = -2ll*mod*mod;
    REP(i, n){
        REP(j, 26){
            init[i][ to[i][j] ] = max(init[i][ to[i][j] ], (LL)val[i][j]);
        }
    }


    matrix_expo(M+1);

    LL res = -2ll*mod*mod;
    REP(i, n){
        res = max(res, big_res[0][i]);
    }

    cout << res << endl;
}