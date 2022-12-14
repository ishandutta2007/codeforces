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

LL ar[7];
LL vv[1001];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f,g,h = 1,x = 1,y,z;
    REP(i, 6)cin >> ar[i];
    for(int i = ar[2]; i <= ar[3]; i++){
        a = ar[2] * (ar[0] - ar[1]);
        b = i * (ar[0] - ar[1]);
        c = i * ar[1];
        d = ar[3] * ar[1];
        if(ar[5] >= c && ar[5] <= d && (ar[4] - ar[5]) >= a && (ar[4] - ar[5]) <= b){
            ar[4] -= ar[5];
            if(ar[0] != ar[1]){
                e = ar[4] / (ar[0] - ar[1]);
                f = ar[4] % (ar[0] - ar[1]);
                for(int j = 1; j <= ar[0] - ar[1]; j++){
                    if(f > 0){
                        f--;
                        cout << e + 1 << " ";
                    }
                    else
                        cout << e << " ";

                }
            }
            e = ar[5] / ar[1];
            f = ar[5] % ar[1];
            for(int j = 1; j <= ar[1]; j++){
                if(f > 0){
                    f--;
                    cout << e + 1 << " ";
                }
                else cout << e << " ";
            }

            return 0;
        }

    }


}