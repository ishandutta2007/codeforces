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

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int ar[101][101], sz[101];
int tmp[101];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b = 0,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a;
    REP(i, a){
        cin >> sz[i];
        REP(j, sz[i])cin >> ar[i][j];
        c = sz[i] / 2;
        REP(j, c)e += ar[i][j];
        for(int j = sz[i] - 1; j >= sz[i] - c; j--)f += ar[i][j];
        if(sz[i] % 2 == 0)tmp[i] = 0;
        else {
            tmp[i] = ar[i][sz[i] - c - 1];
            b++;
        }
    }
    sort(tmp, tmp + a);
    reverse(tmp, tmp + a);
    for(int i = 0; i < a; i++){
        if(i % 2 == 0)e += tmp[i];
        else f += tmp[i];
    }
    cout << e << " " << f << endl;
}