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

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int ar[1000001];
LL res[1000001], disL[1000001], disR[1000001];

main(){
//    freopen("b.in", "r", stdin);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    REP(i, a){
        scanf("%d", &ar[i]);
    }
    for(int i = 0; i < a; i++){
        if(i > 0 && ar[i] != ar[i - 1]){
            c = (i / b);
            if(i % b != 0) c++;
            res[i] += (LL)(c * ar[i]) - disL[0];
        }
        disL[i % b] += (LL)ar[i];
    }
    for(int i = a - 1; i >= 0; i--){
        if(i < a - 1 && ar[i] != ar[i + 1]){
            c = (a - 1 - i) / b;
            if((a - 1 - i) % b != 0) c++;
            res[i] += disR[(a - 1) % b] - (LL)(c * ar[i]);
        }
        disR[i % b] += (LL)ar[i];
    }
    f = linf;
    for(int i = 0; i < a; i++){
        if(i > 0 && ar[i] == ar[i - 1]) continue;
        d = upper_bound(ar, ar + a, ar[i]) - ar - 1;
        g = res[i];
        if(d != i) g += res[d];
        f = min(f, g);
    }
    cout << f*2ll << endl;
}