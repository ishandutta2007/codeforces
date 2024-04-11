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
#define PI         acos(-1.0)
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

double dp[1011];
struct data{
    int x, y, t;
    double p;
};
bool operator<(data a, data b){
    return a.t < b.t;
}
data ar[1001];
double dis(data a, data b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    FOR(i, 1, a + 1) cin >> ar[i].x >> ar[i].y >> ar[i].t >> ar[i].p;
    sort(ar + 1, ar + 1 + a);
    double p = 0;
    for(int i = a; i >= 1; i--){
        dp[i] = ar[i].p;
        for(int j = i + 1; j <= a; j++){
            if(dis(ar[i], ar[j]) <= ar[j].t - ar[i].t)
               dp[i] = max(dp[i], ar[i].p + dp[j]);
        }
        p = max(p, dp[i]);
    }
    cout << fixed << setprecision(10) << p << endl;
}