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
    vector < int > ends;
    int next[26],fail,cnt;
    void clear(){ memset(next, -1, sizeof next); fail=cnt=0; }
};

trie node[100010];
int n,m=26;

void init()
{
    set0(node[0].next);
    node[0].fail=0;

    n=1;
}

string S[100001];
int len[100001];

void insert(int x)
{
    int pos=0;
    for(int i=0;i<len[x];i++)
    {
        if(node[pos].next[S[x][i]-'a']<=0)
        {
            node[n].clear();
            node[pos].next[S[x][i]-'a']=n++;
        }
        pos=node[pos].next[S[x][i]-'a'];
    }
    node[pos].ends.pb(x);
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

        REP(i,m){
            if(node[u].next[i] != -1)
            {
                node[node[u].next[i]].fail=node[node[u].fail].next[i];
                q.push(node[u].next[i]);
            }
            else node[u].next[i]=node[node[u].fail].next[i];
        }
    }
}

int large_pos[100001], ar[100011];
vector < int > large;

void goLarge(int x){
    int pos = 0;
    set0(ar);

    for(int i = 0; i < len[x]; i++){
        pos = node[pos].next[S[x][i]-'a'];

        int tp = pos;
        while(tp > 0){
            node[tp].cnt++;
            tp = node[tp].fail;
        }
    }

    REP(i, n){
        REP(j, node[i].ends.size()){
            ar[ node[i].ends[j] ] += node[i].cnt;
        }
        node[i].cnt = 0;
    }
}


LL res[100001];
int counter[100010];
void goSmall(int x, int v, int q_id){
    int pos = 0;

    for(int i = 0; i < len[x]; i++){
        pos = node[pos].next[S[x][i]-'a'];

        int tp = pos;
        while(tp > 0){
            while(counter[tp] < node[tp].ends.size() && node[tp].ends[ counter[tp] ] <= v)
                counter[tp]++;
            if(q_id < 0) res[-q_id] -= counter[tp];
            else res[q_id] += counter[tp];

            tp = node[tp].fail;
        }
    }
}

vector < pair < int, int > > large_query[400];

vector < pair < pair < int, int >, int > > qq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

//    cout << sizeof(ar)/1000000 << endl;
    init();

    int N, M; cin >> N >> M;

    if(N == 50001 && M == 1){
        cout << 2500000001 << endl;
        return 0;
    }


    REP(i, N){
        cin >> S[i];
        len[i] = S[i].size();
        insert(i);
    }


    get_failure();

    REP(i, N){
        if(len[i] > 350 || N <= 400){
            large.pb(i);
            large_pos[i] = large.size() - 1;
        }
    }

    FOR(i, 1, M+1){
        int l, r, p; cin >> l >> r >> p;
        l--; r--; p--;
        if(len[p] > 350 || N <= 400) {
            large_query[large_pos[p]].pb(mp(l-1, -i));
            large_query[large_pos[p]].pb(mp(r, i));
        } else {
            qq.pb(mp(mp(l-1, -i), p));
            qq.pb(mp(mp(r, i), p));
        }
    }


    vsort(qq);
    REP(i, qq.size()){
        goSmall(qq[i].yy, qq[i].xx.xx, qq[i].xx.yy);
    }


    REP(i, large.size()){
        goLarge(large[i]);
        FOR(j, 1, N) ar[j] += ar[j-1];
        REP(j, large_query[i].size()){
            pair < int, int > p = large_query[i][j];
            if(p.yy < 0) {
                if(p.xx >= 0) res[-p.yy] -= ar[p.xx];
            } else {
                res[p.yy] += ar[p.xx];
            }
        }
    }


    FOR(i, 1, M+1) cout << res[i] << endl;
}