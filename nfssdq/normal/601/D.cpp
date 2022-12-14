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

vector < int > vc[300001];
set < LL > S[300001];
LL base1, base2, md1 = mod, md2 = mod+2, ar[300001], val[300001], res[300001], tmp[2][300001];
LL B[300001], inv[2][300001], pp[2][300001];
string s;
LL mul = 2000000000;
void dfs(int c, int p){
    int mx = -1, sz = 0;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        dfs(vc[c][i], c);
        if(S[vc[c][i]].size() > sz){
            sz = S[vc[c][i]].size();
            mx = vc[c][i];
        }
    }

    if(mx == -1){
        res[c] = 1;
        S[c].insert(0);
        tmp[0][c] = val[c];
        tmp[1][c] = val[c];
        B[c] = 1;
        return;
    }

    swap(S[c], S[mx]);
    REP(i, vc[c].size()){
        int nxt = vc[c][i];
        if(nxt == p || nxt == mx) continue;
        LL v1 = (md1 + (tmp[0][ nxt ] - tmp[0][mx])) % md1;
        LL v2 = (md2 + (tmp[1][ nxt ] - tmp[1][mx])) % md2;
        LL t1 = 1, t2 = 1;
        if(B[ nxt ] < B[mx]) t1 = inv[0][ B[mx] - B[nxt] ];
        else t1 = pp[0][ B[nxt] - B[mx] ];
        if(B[ nxt ] < B[mx]) t2 = inv[1][ B[mx] - B[nxt] ];
        else t2 = pp[1][ B[nxt] - B[mx] ];

        v1 = (v1 * inv[0][B[mx]]) % md1;
        v2 = (v2 * inv[1][B[mx]]) % md2;
        for(auto &vt: S[nxt]){
            LL vt2 = vt % mul, vt1 = vt / mul;
            vt1 = (vt1 * t1 + v1) % md1;
            vt2 = (vt2 * t2 + v2) % md2;
            S[ c ].insert(vt1*mul + vt2);
        }
    }
    LL v1 = (md1 - (base1*tmp[0][mx])%md1 ) % md1;
    LL v2 = (md2 - (base2*tmp[1][mx])%md2 ) % md2;
    B[c] = B[mx] + 1;
    v1 = (v1 * inv[0][ B[c] ]) % md1;
    v2 = (v2 * inv[1][ B[c] ]) % md2;
    S[c].insert( v1*mul+v2 );
    res[c] = S[c].size();
    tmp[0][c] = (val[c] + base1*tmp[0][mx]) % md1;
    tmp[1][c] = (val[c] + base2*tmp[1][mx]) % md2;
//    cout << c << endl;
//    for(auto &vv: S[c]) cout << (vv*pp[B[c]]+tmp[c])%mod << " " ;
//    cout << endl << B[c] << " " << tmp[c] << endl;;
}
/*
b^2x
c-a+by
*/
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0));
    base1 = 27 + rand() % 70;
    pp[0][0] = 1;
    for(int i = 1; i <= 300000; i++) pp[0][i] = (pp[0][i-1] * base1) % md1;
    REP(i, 300001) inv[0][i] = modinverse(pp[0][i], md1);

    base2 = 26 + rand() % 70;
    pp[1][0] = 1;
    for(int i = 1; i <= 300000; i++) pp[1][i] = (pp[1][i-1] * base2) % md2;
    REP(i, 300001) inv[1][i] = modinverse(pp[1][i], md2);

    int n; cin >> n;
    FOR(i, 1, n+1) cin >> ar[i];
    cin >> s;
    FOR(i, 1, n+1) val[i] = s[i-1] - 'a' + 1;

    REP(i, n-1){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }

    dfs(1, 0);

    int mx = 0, cnt = 0;
    FOR(i, 1, n+1){
        if(res[i] + ar[i] > mx){
            mx = res[i] + ar[i];
            cnt = 1;
        } else if(res[i] + ar[i] == mx) cnt++;
    }

    cout << mx << endl << cnt << endl;
}