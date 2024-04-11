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

int ar[5];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d,e,f,g,h,x,y,z;
    cin >> a;
    REP(i, a){
        cin >> b;
        ar[b]++;
    }
    c = d = 0;
    f = min(ar[1], ar[2]);
    ar[1] -= f;
    ar[2] -= f;
    c += f;
    d += f;
    d += (ar[1] / 3) * 2;
    c += ar[1] / 3;
    ar[1] %= 3;
    d += (ar[2] / 3) * 2;
    c += (ar[2] / 3) * 2;
    ar[2] %= 3;
    c += ar[3];
    if(ar[1] == ar[2]){
        d += ar[1];
        cout << d;
        return 0;
    }
    else if(ar[2] == 2){
        if(ar[1] == 1 && ar[4] > 0){
            d += 2;
            cout << d;
            return 0;
        }
        else if(ar[1] == 0 && ar[4] > 0){
            d += 2;
            cout << d;
            return 0;
        }
        else if(c >= (1 + ar[1])){
            d += 2 + ar[1];
            cout << d;
            return 0;
        }
        else {
            d = -1;
            cout << d;
            return 0;
        }
    }
    else if(ar[2] == 1){
        if(ar[1] == 2 && c >= 1){
            d += 2;
            cout << d;
            return 0;
        }
        else if(ar[1] == 2 && ar[4] > 1){
            d += 3;
            cout << d;
            return 0;
        }
        else if(ar[1] == 0 && ar[4] > 0){
            d++;
            cout << d;
            return 0;
        }
        else if(c >= 2){
            d += 2;
            cout << d;
            return 0;
        }
        else {
            d = -1;
            cout << d;
            return 0;
        }
    }
    else if(ar[2] == 0){
        if(ar[1] == 2 && ar[4] > 0){
            d += 2;
            cout << d;
            return 0;
        }
        else if(c >= ar[1]){
            d += ar[1];
            cout << d;
            return 0;
        }
        else if(ar[1] == 1 && ar[4] > 1){
            d += 2;
            cout << d;
            return 0;
        }
        else {
            d = -1;
            cout << d;
            return 0;
        }
    }
}