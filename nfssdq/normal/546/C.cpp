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

typedef pair < deque < int >, deque < int > > pvv;
set < pvv > S;
void go(pvv a, int mv){
    if(S.count(a)){
        cout << -1 << endl;
        return;
    }
    S.insert(a);
    if(a.xx.size() == 0){
        cout << mv - 1 << " " << 2 << endl;
        return;
    } else if(a.yy.size() == 0){
        cout << mv - 1 << " " << 1 << endl;
        return;
    }

    int p = a.xx[0], q = a.yy[0];
    if(p > q){
        a.xx.pb(q);
        a.xx.pb(p);
    }
    else {
        a.yy.pb(p);
        a.yy.pb(q);
    }

    a.xx.pop_front();
    a.yy.pop_front();

    go(a, mv + 1);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    deque < int > da, db;
    int k1, k2;
    cin >> k1;
    REP(i, k1){
        int v; cin >> v;
        da.pb(v);
    }
    cin >> k2;
    REP(i, k2){
        int v; cin >> v;
        db.pb(v);
    }

    go(mp(da, db), 1);
}