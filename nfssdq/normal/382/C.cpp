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

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL ar[100001];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 1,x,y,z;
    cin >> a;
    REP(i, a) cin >> ar[i];
    sort(ar, ar + a);
    if(a == 1){
        cout << -1 << endl;
        return 0;
    }
    vector < int > vc;
    if(a == 2){
        b = ar[1] - ar[0];
        vc.pb(ar[0] - b);
        if(b != 0)vc.pb(ar[1] + b);
        if(b % 2 == 0 && b != 0)vc.pb(ar[0] + (b / 2));
    }
    else {
        map < int, int > mm;
        vector < int > vp;
        FOR(i, 1, a){
            mm[ar[i] - ar[i - 1]]++;
        }
        for(map < int, int > ::iterator it = mm.begin(); it != mm.end(); it++)
            vp.pb((*it).xx);
        if(mm.size() == 2){
            vsort(vp);
            if(mm[vp[1]] > 1 || vp[1] != vp[0] * 2ll){
                goto pp;
            }
            for(int i = 1; i < a; i++){
                c = ar[i] - ar[i - 1];
                if(c == vp[1])vc.pb(ar[i] - (c / 2));
            }
            pp:;
        }
        else if(mm.size() == 1){
            vc.pb(ar[a - 1] + vp[0]);
            if(vp[0] != 0)vc.pb(ar[0] - vp[0]);
        }
    }
    vsort(vc);
    cout << vc.size() << endl;
    REP(i, vc.size())cout << vc[i] << " ";
}