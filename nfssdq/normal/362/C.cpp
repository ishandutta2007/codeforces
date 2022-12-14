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

int ar[5001], sum[5005][5005], mv[5005][5005];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a, b = 0,c,d,e = 0,f,g,h = 1,x = 5000*6000,y = 0,z;
    cin >> a;
    FOR(i, 1, a + 1)cin >> ar[i];
    FOR(i, 1, a + 1){
        for(int j = 1; j <= a; j++){
            sum[i][j] = sum[i][j - 1];
            if(ar[j] > ar[i])sum[i][j]++;
            mv[i][j] = mv[i][j - 1];
            if(ar[j] < ar[i])mv[i][j]++;
        }
        b += sum[i][i];
    }
    FOR(i, 1, a + 1){
        FOR(j, i + 1, a + 1){
            c = b;
            c -= sum[i][i] + sum[j][j];
            c += sum[i][j - 1] + sum[j][i - 1];
            c += mv[j][j - 1] - mv[j][i] - (mv[i][j - 1] - mv[i][i]);
            if(c < x){
                x = c; y = 1;
            }
            else if(c == x)y++;
        }
    }
    cout << x << " " << y << endl;
}