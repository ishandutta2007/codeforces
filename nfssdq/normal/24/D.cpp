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

double dp[1011][1011];
double A[1011], B[1011], C[1011], D[1011], Cp[1011], Dp[1011];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b >> x >> y;
    if(b == 1){
        for(int i = a - 1; i >= 1; i--){
            dp[i][1] = (1.0 + dp[i + 1][1]/2.0 ) * 2.0;
        }
        cout << fixed << setprecision(8) << dp[x][y] << endl;
        return 0;
    }
    for(int i = 1; i <= b; i++){
        if(i == 1){
            B[i] = -2.0/3.0;
            C[i] = 1.0/3.0;
        } else if(i == b){
            B[i] = -2.0/3.0;
            A[i] = 1.0/3.0;
        } else {
            A[i] = C[i] = 0.25;
            B[i] = -3.0/4.0;
        }
    }
    for(int i = a - 1; i >= 1; i--){
        for(int j = 1; j <= b; j++){
            if(j == 1 || j == b) D[j] = -1.0 - (dp[i + 1][j] / 3.0);
            else D[j] = -1.0 - (dp[i + 1][j] / 4.0);
        }
        for(int j = 1; j <= b; j++){
            if(j == 1)Cp[j] = C[j] / B[j];
            else Cp[j] = C[j] / (B[j] - A[j] * Cp[j - 1]);
            if(j == 1) Dp[j] = D[j] / B[j];
            else Dp[j] = (D[j] - A[j]*Dp[j - 1]) / (B[j] - A[j]*Cp[j - 1]);
        }
        for(int j = b; j >= 1; j--){
            if(j == b) dp[i][j] = Dp[j];
            else dp[i][j] = Dp[j] - (Cp[j] * dp[i][j + 1]);
        }
    }
    cout << fixed << setprecision(8) << dp[x][y] << endl;
}
/*
0.25(j-1) + -0.75(j) + 0.25(j+1) + 0.25*v = -1
-0.66*(j) + 0.33(j+1) + 0.33(v) = -1
-0.66*(j) + 0.33(j-1) + 0.33(v) = -1
*/