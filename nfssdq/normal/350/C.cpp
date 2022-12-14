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
#define mod        100000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

pair < LL, LL > pp[100001];
pair < LL, LL > ar[100001];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d,e,f,g,h,x,y,z;
    cin >> a;
    REP(i, a){
        cin >> b >> c;
        pp[i].xx = b, pp[i].yy = c;
        ar[i].xx = abs(b) + abs(c);  ar[i].yy = i;
    }
    sort(ar, ar + a);
    vector < pair < LL, pair < LL, LL > > > out;
    REP(i, a){
        if(pp[ar[i].yy].xx > 0)out.pb(mp(1, mp(pp[ar[i].yy].xx, 0)));
        if(pp[ar[i].yy].xx < 0)out.pb(mp(1, mp(pp[ar[i].yy].xx * -1, 1)));
        if(pp[ar[i].yy].yy > 0)out.pb(mp(1, mp(pp[ar[i].yy].yy, 2)));
        if(pp[ar[i].yy].yy < 0)out.pb(mp(1, mp(pp[ar[i].yy].yy * -1, 3)));
        out.pb(mp(2, mp(5, 5)));
        if(pp[ar[i].yy].yy > 0)out.pb(mp(1, mp(pp[ar[i].yy].yy, 3)));
        if(pp[ar[i].yy].yy < 0)out.pb(mp(1, mp(pp[ar[i].yy].yy * -1, 2)));
        if(pp[ar[i].yy].xx > 0)out.pb(mp(1, mp(pp[ar[i].yy].xx, 1)));
        if(pp[ar[i].yy].xx < 0)out.pb(mp(1, mp(pp[ar[i].yy].xx * -1, 0)));
        out.pb(mp(3, mp(5, 5)));
    }
    cout << out.size() << endl;
    REP(i, out.size()){
        if(out[i].xx == 1){
            cout << 1 << " " << out[i].yy.xx << " ";
            if(out[i].yy.yy == 0)cout << "R";
            if(out[i].yy.yy == 1)cout << "L";
            if(out[i].yy.yy == 2)cout << "U";
            if(out[i].yy.yy == 3)cout << "D";
            cout << endl;
        }
        else cout << out[i].xx << endl;
    }
}