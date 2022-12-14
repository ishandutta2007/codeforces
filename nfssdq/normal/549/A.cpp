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


string s[55];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    REP(i, n) cin >> s[i];

    int cnt = 0;
    REP(i, n - 1){
        REP(j, m-1){
            int ar[5] = {0};
            if(s[i][j] == 'f' || s[i+1][j] == 'f' || s[i][j + 1] == 'f' || s[i+1][j+1] == 'f') ar[0] = 1;
            if(s[i][j] == 'a' || s[i+1][j] == 'a' || s[i][j + 1] == 'a' || s[i+1][j+1] == 'a') ar[1] = 1;
            if(s[i][j] == 'c' || s[i+1][j] == 'c' || s[i][j + 1] == 'c' || s[i+1][j+1] == 'c') ar[2] = 1;
            if(s[i][j] == 'e' || s[i+1][j] == 'e' || s[i][j + 1] == 'e' || s[i+1][j+1] == 'e') ar[3] = 1;
            if(ar[0]+ar[1]+ar[2]+ar[3] == 4) cnt++;
        }
    }
    cout << cnt << endl;
}