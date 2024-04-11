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

LL bit[400001];
void add(int x, int v){
    for(int i = x; i <= 400000; i += i & -i) bit[i] += v;
}
LL query(int x){
    LL ret = 0;
    for(int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

LL ar[100001][4];
map < LL, LL > mx, my;
vector < pair < LL, LL > > horizontal[400001], vertical[400001];
vector < int > in[400001], out[400001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n) {
        REP(j, 4) cin >> ar[i][j];
        mx[ar[i][0]] = mx[ar[i][2]] = my[ar[i][1]] = my[ar[i][3]] = 1;
        if(ar[i][0] > ar[i][2]) swap(ar[i][0], ar[i][2]);
        if(ar[i][1] > ar[i][3]) swap(ar[i][1], ar[i][3]);
    }
    int c1 = 0, c2 = 0;
    for(auto &v: mx){
        v.yy = ++c1;
    }
    for(auto &v: my){
        v.yy = ++c2;
    }

    REP(i, n){
        if(ar[i][0] == ar[i][2]) horizontal[ mx[ar[i][0]] ].pb(mp(ar[i][1], ar[i][3]));
        else vertical[ my[ar[i][1]] ].pb(mp(ar[i][0], ar[i][2]));
    }
    LL res = 0;
    for(int i = 1; i <= c1; i++){
        vsort(horizontal[i]);
        if(horizontal[i].size() == 0) continue;
        int last = 0;
        for(int j = 1; j < horizontal[i].size(); j++){
            if(horizontal[i][j].xx <= horizontal[i][last].yy){
                horizontal[i][last].yy = max(horizontal[i][last].yy, horizontal[i][j].yy);
            } else {
                res += horizontal[i][last].yy - horizontal[i][last].xx + 1;
                in[ my[horizontal[i][last].xx] ].pb(i);
                out[my[horizontal[i][last].yy] ].pb(i);
                last = j;
            }
        }
        res += horizontal[i][last].yy - horizontal[i][last].xx + 1;
        in[ my[horizontal[i][last].xx] ].pb(i);
        out[my[horizontal[i][last].yy] ].pb(i);

    }

    for(int i = 1; i <= c2; i++){
        vsort(vertical[i]);
        for(int j = 0; j < in[i].size(); j++){
            add(in[i][j], 1);
        }
        if(vertical[i].size() == 0) {
            for(int j = 0; j < out[i].size(); j++){
                add(out[i][j], -1);
            }
            continue;
        }
        int last = 0;
        for(int j = 1; j < vertical[i].size(); j++){
            if(vertical[i][j].xx <= vertical[i][last].yy){
                vertical[i][last].yy = max(vertical[i][last].yy, vertical[i][j].yy);
            } else {
                res += vertical[i][last].yy - vertical[i][last].xx + 1;
                res -= query(mx[vertical[i][last].yy]) - query(mx[vertical[i][last].xx]-1);
                last = j;
            }
        }
        res += vertical[i][last].yy - vertical[i][last].xx + 1;
        res -= query(mx[vertical[i][last].yy]) - query(mx[vertical[i][last].xx]-1);

        for(int j = 0; j < out[i].size(); j++){
            add(out[i][j], -1);
        }

    }

    cout << res << endl;
}