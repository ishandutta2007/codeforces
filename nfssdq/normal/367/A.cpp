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

LL ar[100001][5];
char pp[100001];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f,g,h = 0,x = 1,y,z;
    cin >> pp;
    a = strlen(pp);
    REP(i, a){
        REP(j, 3)ar[i + 1][j] = ar[i][j];
        if(pp[i] == 'x')ar[i + 1][0]++;
        if(pp[i] == 'y')ar[i + 1][1]++;
        if(pp[i] == 'z')ar[i + 1][2]++;
    }
    cin >> b;
    REP(i, b){
        cin >> c >> d;
        if(d - c + 1 <= 2){
            cout << "YES" << endl;
            continue;
        }
        e = ar[d][0] - ar[c - 1][0];
        f = ar[d][1] - ar[c - 1][1];
        g = ar[d][2] - ar[c - 1][2];
        h = min(e, min(f, g));
        if(abs(h - e) > 1 || abs(h - f) > 1 || abs(h - g) > 1)cout << "NO" << endl;
        else cout << "YES" << endl;

    }
}