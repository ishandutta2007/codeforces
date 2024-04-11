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

LL dp[1000001], mx[1000001]; string s;
LL go(LL i){
    if(i == 0)return 1;
    if(dp[i] != -1)return dp[i];
    dp[i] = 0;
    if(mx[i] == mx[i - 1])dp[i] = go(i - 1);
    LL c = s[i - 1] - '0' + s[i - 2] - '0';
    if(c == 9 && mx[i] == 1 + mx[i - 2])dp[i] += go(i - 2);
    return dp[i];
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f,g,h = 1,x,y,z;
    cin >> s;
    memset(dp, -1, sizeof dp);
    for(int i = 2; i<= s.size(); i++){
        mx[i] = mx[i - 1];
        c = s[i - 1] - '0' + s[i - 2] - '0';
        if(c == 9)mx[i] = max(mx[i], 1 + mx[i - 2]);
    }
    go(s.size());
    cout << dp[s.size()] << endl;
}