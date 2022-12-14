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

LL ar[100001], grundy[129][2];
int go(int v){
    if(v <= 128) return grundy[v][1];
    if(v % 2 == 1) return 0;
    int p = go(v/2);
    if(p == 0 || p == 2) return 1;
    if(p == 1) return 2;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    grundy[0][0] = grundy[0][1] = 0;
    for(int i = 1; i < 129; i++){
        REP(j, 2){
            set < int > s;
            s.insert(grundy[i-1][j]);
            if(i % 2 == 0){
                if(j == 0) s.insert(0);
                else s.insert(grundy[i/2][j]);
            }

            for(int k = 0; ;k++) if(s.count(k) == 0){
                grundy[i][j] = k;
                break;
            }

        }
    }

    int n, k; cin >> n >> k;
    k = k % 2;
    int res = 0;
    REP(i, n) {
        cin >> ar[i];
        if(ar[i] <= 128) res ^= grundy[ar[i]][k];
        else if(k == 0){
            if(ar[i] % 2 == 0) res ^= 1;
        } else {
            res ^= go(ar[i]);
        }
    }
    if(res) cout << "Kevin" << endl;
    else cout << "Nicky" << endl;
}