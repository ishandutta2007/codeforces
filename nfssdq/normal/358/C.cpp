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
#define linf       (1ll<<62)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

vector < pair < LL, LL > > vc;
LL ar[100001];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f,g,h = -1,x,y,z;
    cin >> a;
    REP(i, a){
        cin >> b;
        if(b == 0){
            vsort(vc);
            c = vc.size();
            d = 3;
            for(int j = c - 1; j >= 0; j--)ar[vc[j].yy] = max(d--, 0ll);
            for(int j = h + 1; j < i; j++){
                if(ar[j] == 3)cout << "pushStack" << endl;
                else if(ar[j] == 2)cout << "pushQueue" << endl;
                else if(ar[j] == 1) cout << "pushFront" << endl;
                else cout << "pushBack" << endl;
            }
            if(c == 0)cout << 0 << endl;
            if(c == 1)cout << "1 popStack" << endl;
            if(c == 2)cout << "2 popStack popQueue" << endl;
            if(c > 2)cout << "3 popStack popQueue popFront" << endl;
            h = i;
            vc.clear();
        }
        else vc.pb(mp(b, i));
    }
    if(vc.size() > 0)REP(i, vc.size())cout << "pushBack" << endl;
}