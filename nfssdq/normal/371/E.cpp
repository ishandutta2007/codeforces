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

template <class T> inline T bigmod(T p,T e,T M) {
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b) {if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M) {return bigmod(a,M-2,M);}

pair < LL, LL > pp[1000001];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f,g,h = 1,x = 1,y,z;
    cin >> a;
    REP(i, a){
        cin >> pp[i].xx;
        pp[i].yy = i;
    }
    cin >> b;
    sort(pp, pp + a);
    c = 1 - b; f = 0; g = linf; h = 0;
    REP(i, b){
        e += pp[i].xx * (c + i);
        c++;
        f += pp[i].xx;
    }
    g = e; h = 0;
    for(int i = 1; i < a; i++){
        if(i + b - 1 >= a)break;
        x = i + b - 1;
        e -= pp[i - 1].xx * (1ll - b);
        f -= pp[i - 1].xx;
        e += pp[x].xx * (b - 1);
        e -= f * 2;
        f += pp[x].xx;
        if(e < g){
            g = e;
            h = i;
        }
    }
    for(int i = h; i < h + b; i++)cout << pp[i].yy + 1 << " ";


}