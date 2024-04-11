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

template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL dp[3005][5];
LL ar[3005][3];

LL go(LL pos, LL fl){
    if(pos == 1){
        return ar[pos][fl];
    }
    LL &ret = dp[pos][fl];
    if(ret != -1)return ret;
    ret = 0;
    if(fl == 0){
        ret = max(ar[pos][0] + go(pos - 1, 1), ar[pos][1] + go(pos - 1, 0));
    }
    else {
        ret = max(ar[pos][1] + go(pos - 1, 1), ar[pos][2] + go(pos - 1, 0));
    }
    return ret;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f,g,h = -1,x,y,z;
    memset(dp, -1, sizeof dp);
    cin >> a;
    FOR(i, 1, a + 1)cin >> ar[i][0];
    FOR(i, 1, a + 1)cin >> ar[i][1];
    FOR(i, 1, a + 1)cin >> ar[i][2];
    cout << go(a, 0) << endl;
}