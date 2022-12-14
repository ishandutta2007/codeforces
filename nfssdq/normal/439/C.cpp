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
#define PI         2.0*acos(0.0)
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

vector < int > vc[100001];
vector < int > odd, even;
vector < pair < int, int > > vp;
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b >> c;
    REP(i, a){
        cin >> d;
        if(d % 2 == 0) even.pb(d);
        else odd.pb(d);
    }
    b -= c;
    if(odd.size() < b || (odd.size() - b) % 2 != 0){
        cout << "NO" << endl;
        return 0;
    }
    if(((odd.size() - b)/2) + even.size() < c){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    REP(i, b){
        vc[i].pb(odd[i]);
    }
    for(int i = b; i < odd.size(); i += 2) vp.pb(mp(odd[i], odd[i + 1]));
    REP(i, even.size()) vp.pb(mp(even[i], 0));
    d = 0;
    for(int i = b; i < b + c; i++){
        vc[i].pb(vp[d].xx);
        if(vp[d].yy != 0) vc[i].pb(vp[d].yy);
        d++;
    }
    for(int i = d; i < vp.size(); i++){
        vc[b + c - 1].pb(vp[i].xx);
        if(vp[i].yy != 0) vc[b + c - 1].pb(vp[i].yy);
    }
    REP(i, b+c){
        cout << vc[i].size();
        REP(j, vc[i].size()) cout << " " << vc[i][j];
        cout << endl;
    }
}