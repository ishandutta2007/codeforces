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

int st[100001], ed[100001], sz[100001], t = 0;
vector < int > vc[100001], query[100001];
void dfs(int c, int p){
    st[c] = ++t;
    sz[c] = 1;
    REP(i, vc[c].size()){
        if(vc[c][i] != p) {
            dfs(vc[c][i], c);
            sz[c] += sz[vc[c][i]];
        }
    }
    ed[c] = t;
}
int seg[400001], cnt[400001], n;
void insert(int idx, int s, int e, int sst, int sed, int v){
    if(s == sst && e == sed){
        seg[idx] += v;
        if(seg[idx]) cnt[idx] = e - s + 1;
        else if(s != e) cnt[idx] = cnt[idx * 2 + 1] + cnt[idx * 2 + 2];
        else cnt[idx] = 0;
        return;
    }
    int mid = (s + e) / 2;
    if(sed <= mid) insert(idx * 2 + 1, s, mid, sst, sed, v);
    else if(sst > mid) insert(idx * 2 + 2, mid + 1, e, sst, sed, v);
    else {
        insert(idx * 2 + 1, s, mid, sst, mid, v);
        insert(idx * 2 + 2, mid + 1, e, mid + 1, sed, v);
    }
    if(seg[idx]) cnt[idx] = e - s + 1;
    else cnt[idx] = cnt[idx * 2 + 1] + cnt[idx * 2 + 2];
}
int res[100001];
void dfs2(int c, int p, int f){
    if(query[c].size() > 0) f = 1;
    REP(i, query[c].size()){
        int a = query[c][i];
        if((st[c] >= st[a] && st[c] <= ed[a]) || (st[a] >= st[c] && st[a] <= ed[c])){
            continue;
        }
        insert(0, 1, n, st[a], ed[a], 1);
    }
    if(f){
        res[c] = (sz[c] - 1) + cnt[0];
        REP(i, vc[c].size()){
            int a = vc[c][i];
            if(a == p) continue;
            insert(0, 1, n, st[a], ed[a], 1);
        }
        insert(0, 1, n, st[c], st[c], 1);
        REP(i, vc[c].size()){
            int a = vc[c][i];
            if(a == p) continue;
            insert(0, 1, n, st[a], ed[a], -1);
            dfs2(a, c, f);
            insert(0, 1, n, st[a], ed[a], 1);
        }
        REP(i, vc[c].size()){
            int a = vc[c][i];
            if(a == p) continue;
            insert(0, 1, n, st[a], ed[a], -1);
        }
        insert(0, 1, n, st[c], st[c], -1);
    } else {
        REP(i, vc[c].size()){
            if(vc[c][i] != p) dfs2(vc[c][i], c, f);
        }
    }
    REP(i, query[c].size()){
        int a = query[c][i];
        if((st[c] >= st[a] && st[c] <= ed[a]) || (st[a] >= st[c] && st[a] <= ed[c])){
            continue;
        }
        insert(0, 1, n, st[a], ed[a], -1);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b; n = a;
    REP(i, a - 1){
        cin >> c >> d;
        vc[c].pb(d);
        vc[d].pb(c);
    }
    dfs(1, 0);
    REP(i, b){
        cin >> c >> d;
        query[c].pb(d);
        query[d].pb(c);
    }
    dfs2(1, 0, 0);
    FOR(i, 1, a + 1) cout << res[i] << " ";
    cout << endl;
}