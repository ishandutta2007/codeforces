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

set < int > row, col;
set < pair < int, pair < int, int > > > vrow, vcol;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL w, h, n;
    cin >> w >> h >> n;
    row.insert(0);
    row.insert(w);
    vrow.insert( mp(w, mp(0, w)));

    col.insert(0);
    col.insert(h);
    vcol.insert( mp(h, mp(0, h)));

    REP(i, n){
        LL v;
        string s; cin >> s >> v;
        if(s == "H"){
            set<int>::iterator it = col.lower_bound(v);
            pair<int,int> p;
            p.yy = (*it); it--;
            p.xx = (*it);
            col.insert(v);

            pair< int, pair<int,int> > ps = mp(p.yy-p.xx, p);
            vcol.erase(ps);

            vcol.insert( mp(v-p.xx, mp(p.xx, v)));
            vcol.insert( mp(p.yy-v, mp(v, p.yy)));

        } else {
            set<int>::iterator it = row.lower_bound(v);
            pair<int,int> p;
            p.yy = (*it); it--;
            p.xx = (*it);
            row.insert(v);

            pair< int, pair<int,int> > ps = mp(p.yy-p.xx, p);
            vrow.erase(ps);

            vrow.insert( mp(v-p.xx, mp(p.xx, v)));
            vrow.insert( mp(p.yy-v, mp(v, p.yy)));

        }

        set<pair<int, pair<int,int> > >::iterator it = vrow.end();
        it--;

        LL res = (*it).xx;


        it = vcol.end(); it--;
        res *= (*it).xx;

        cout << res << endl;
    }
}