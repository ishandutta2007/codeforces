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

LL ar[403][403], sz[603], dp[403][403][2], l;
LL go(int c, int d, int f){
    if(c < 0){
        if(f == 0) return 0;
        return d == 0;
    }
    LL &ret = dp[c][d][f];
    if(f && ret != -1) return ret;
    ret = 0;
    REP(i, 10){
        if(f == 0 && i < ar[l][c]) continue;
        if(i > d) break;
        if(f == 0 && i == ar[l][c]) ret |= go(c - 1, d - i, 0);
        else ret |= go(c - 1, d - i, 1);
    }
    return ret;
}
int main() {
    ios_base:: sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 1,g,h = 0,x,y,z = 0;
    cin >> a;
    REP(i, a) cin >> sz[i];
    for(int i = 0; i < 403; i++){
        if(sz[0] <= 9) {
            ar[0][i] = sz[0];
            sz[0] = 0;
        } else {
            ar[0][i] = 9;
            sz[0] -= 9;
        }
    }
    memset(dp, -1, sizeof dp);
    for(int i = 1; i < a; i++){
        l = i - 1;
        f = 0;
        for(int j = 401; j >= 0; j--){
            REP(k, 10){
                if(f == 0 && k < ar[l][j]) continue;
                if(f == 0 && k == ar[l][j]) c = go(j - 1, sz[i]-k, 0);
                else c = go(j - 1, sz[i]-k, 1);
                if(c){
                    ar[i][j] = k;
                    if(f == 0 && k == ar[l][j]) f = 0;
                    else f = 1;
                    sz[i] -= k;
                    break;
                }
            }
        }
    }
    REP(i, a){
        f = 0;
        for(int j = 401; j >= 0; j--){
            if(ar[i][j] == 0 && f == 0) continue;
            cout << ar[i][j];
            f = 1;
        }
        cout << endl;
    }
}