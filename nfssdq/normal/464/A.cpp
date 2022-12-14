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

int n, p, dp[1001][27][27][2];
string s;
int go(int c, int p1, int p2, int f){
    if(c == n) return f;
    int &ret = dp[c][p1][p2][f];
    if(ret != -1) return ret;
    ret = 0;
    int v = s[c] - 'a' + 1;
    for(int i = 1; i <= p; i++){
        if(p1 == i || p2 == i) continue;
        if(f == 0 && i < v) continue;
        if((f == 0 && i == v) || f) {
            ret |= go(c + 1, p2, i, f);
        }
        if(f == 0 && i > v){
            ret |= go(c + 1, p2, i, 1);
        }
    }
    return ret;
}
char res[1111];
int print(int c, int p1, int p2, int f){
    if(c == n) return (f == 0 ? 0 : 1);
    if(go(c, p1, p2, f) == 0) return 0;
    int v = s[c] - 'a' + 1;
    for(int i = 1; i <= p; i++){
        if(p1 == i || p2 == i) continue;
        if(f == 0 && i < v) continue;
        res[c] = (char)(i + 'a' - 1);
        if((f == 0 && i == v) || f) {
            int t = print(c + 1, p2, i, f);
            if(t == 1) return t;
        }
        if(f == 0 && i > v){
            int t = print(c + 1, p2, i, 1);
            if(t == 1) return t;
        }
    }
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    cin >> n >> p;
    cin >> s;
    memset(dp, -1, sizeof dp);
    a = go(0, 0, 0, 0);
    a = print(0, 0, 0, 0);
    if(a == 0) cout << "NO" << endl;
    else cout << res << endl;
}