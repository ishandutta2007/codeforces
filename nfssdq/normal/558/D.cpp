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


pair < LL, LL > pp[2][100001];
vector < pair < LL, LL > > vc;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL h, q; cin >> h >> q;
    int c1 = 0, c2 = 0;

    while(q--){
        LL lvl, l, r, ans;
        cin >> lvl >> l >> r >> ans;
        for(int j = lvl + 1; j <= h; j++){
            l *= 2ll;
            r = (r * 2ll + 1ll);
        }
        if(ans == 0){
            pp[ans][c1++] = mp(l, r);
        } else {
            pp[ans][c2++] = mp(l, r);
        }
    }

    LL l = 1, r = 1, mx, mn;
    for(int i = 2; i <= h; i++){
        l *= 2ll;
        r = (r * 2ll + 1ll);
    }
    mx = r; mn = l;

    REP(i, c2){
        if(pp[1][i].xx > r || pp[1][i].yy < l){
            cout << "Game cheated!" << endl;
            return 0;
        }
        l = max(l, pp[1][i].xx);
        r = min(r, pp[1][i].yy);
    }

    sort(pp[0], pp[0] + c1);

    LL rgt = mn - 1;
    REP(i, c1){
        if(pp[0][i].yy <= rgt) continue;
        if(pp[0][i].xx > rgt+1){
            vc.pb(mp(rgt + 1, pp[0][i].xx - 1));
        }
        rgt = max(rgt, pp[0][i].yy);
    }
    if(rgt < mx) vc.pb(mp(rgt+1, mx));

    LL sum = 0, last = 0;
    REP(i, vc.size()){
        if(vc[i].xx > r || vc[i].yy < l) continue;
        LL pl = max(l, vc[i].xx);
        LL pr = min(r, vc[i].yy);
        sum += pr - pl + 1;
        last = pl;
    }

    if(sum == 0){
        cout << "Game cheated!" << endl;
        return 0;
    }
    if(sum == 1){
        cout << last << endl;
    } else {
        cout << "Data not sufficient!" << endl;
    }
}