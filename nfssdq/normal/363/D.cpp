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

int ar[300001];
int bk[100001];
int go(int l, int t, int a, int b){
    if(l >= a)return 0;
    int tv = t;
    REP(i, l + 1){
        if(bk[i] > ar[i]){
            if(tv < bk[i] - ar[i])return 0;
            tv -= bk[i] - ar[i];
        }
    }
    return 1;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a, b = 0,c,d,e = 0,f,g,h = 1,x = 1,y,z;
    cin >> a >> b >> c;
    REP(i, a)cin >> ar[i];
    sort(ar, ar + a);
    REP(i, b)cin >> bk[i];
    sort(bk, bk + b);
    if(bk[0] > ar[a - 1] + c){
        cout << "0 0" << endl;
        return 0;
    }
    b = min(a, b);
    d = 0, e =  b - 1, f= (d + e) / 2;
    while(d < f){
        sort(ar, ar + a);
        reverse(ar, ar + a);
        reverse(ar, ar + f + 1);
        int pp = go(f, c, b, a);
        if(pp == 1)d = f;
        else e = f - 1;
        f = (d + e) / 2;
    }
    if(f < b - 1){
        sort(ar, ar + a);
        reverse(ar, ar + a);
        reverse(ar, ar + f + 2);
        int pp = go(f + 1, c, b, a);
        if(pp == 1)f++;
    }
    e = 0;
    REP(i, f + 1)e += bk[i];
    e -= c;
    e = max(0ll, e);
    cout << f + 1 << " " << e << endl;
}