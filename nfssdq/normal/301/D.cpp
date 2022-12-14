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
#define ALL(A)     A.begin(), A.end()
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

int bit[200001];
void insert(int x, int v){
    for(int i = x; i <= 200000; i += i & -i) bit[i] += v;
}
int query(int x){
    int ret = 0;
    for(int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}
vector < pair < int, int > > vl[200001], vr[200001];
int ar[200001], res[200001], pos[200001];
vector < int > factor[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    for(int i = 1; i <= 200000; i++){
        for(int j = i * 2; j <= 200000; j += i) factor[j].pb(i);
    }
    cin >> a >> b;
    FOR(i, 1, a + 1) {
        cin >> ar[i];
        pos[ar[i]] = i;
    }
    REP(i, b){
        cin >> c >> d;
        vl[c].pb(mp(d, i));
        vr[d].pb(mp(c, i));
        res[i] += d - c + 1;
    }
    FOR(i, 1, a + 1){
        REP(j, factor[ar[i]].size()){
            if(pos[ factor[ ar[i] ][j] ] < i){
                insert(1, 1);
                insert(pos[ factor[ ar[i] ][j] ] + 1, -1);
            }
        }
        REP(j, vr[i].size()){
            res[vr[i][j].yy] += query(vr[i][j].xx);
        }
    }
    set0(bit);
    for(int i = a; i >= 1; i--){
        REP(j, factor[ar[i]].size()){
            if(pos[ factor[ ar[i] ][j] ] > i){
                insert(pos[ factor[ ar[i] ][j] ], 1);
            }
        }
        REP(j, vl[i].size()){
            res[vl[i][j].yy] += query(vl[i][j].xx);
        }
    }
    REP(i, b) cout << res[i] << endl;
}