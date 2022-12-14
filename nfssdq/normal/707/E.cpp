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

vector < pair<int,int> > bulbs[2001];
vector < LL > weight[2001];

LL bit[2222][2222];
void insert(int x, int y, LL v){
    for(int i = x; i <= 2000; i += i & -i){
        for(int j = y; j <= 2000; j += j & -j) bit[i][j] += v;
    }
}
LL query(int x, int y){
    LL ret = 0;
    for(int i = x; i > 0; i -= i & -i){
        for(int j = y; j > 0; j -= j & -j) ret += bit[i][j];
    }
    return ret;
}


vector < int > change[2001], X1, Y1, X2, Y2, T;
LL res[2001];

int main() {
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        int sz; cin >> sz;
        while(sz--){
            int x, y; LL v; scanf("%d %d %I64d", &x, &y, &v);
            bulbs[i].pb(mp(x,y));
            weight[i].pb(v);
        }
    }


    char ss[100];
    int Q; cin >> Q;
    FOR(i, 1, Q+1){
        scanf("%s", ss);
        if(ss[0] == 'S'){
            int x; scanf("%d", &x);
            change[x].pb(i);
        } else {
            int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            X1.pb(x1);
            Y1.pb(y1);
            X2.pb(x2);
            Y2.pb(y2);
            T.pb(i);
        }
    }

    FOR(i, 1, k+1){
        REP(j, bulbs[i].size()){
            insert(bulbs[i][j].xx, bulbs[i][j].yy, weight[i][j]);
        }
        int lft = 0, fl = 0;
        REP(j, T.size()){
            while(lft < change[i].size() && change[i][lft] < T[j]){
                lft++;
                fl ^= 1;
            }
            if(fl == 0){
                res[j] += query(X2[j], Y2[j]) - query(X1[j]-1, Y2[j]) - query(X2[j], Y1[j]-1) + query(X1[j]-1, Y1[j]-1);

            }
        }
        REP(j, bulbs[i].size()){
            insert(bulbs[i][j].xx, bulbs[i][j].yy, -weight[i][j]);
        }
    }

    REP(i, T.size()) cout << res[i] << endl;
}