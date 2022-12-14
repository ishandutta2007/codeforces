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

string S, T;
int on[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n >> S >> T;
    int st = -1, ed = -1;
    REP(i, n){
        if(S[i] != T[i]) on[i] = 1;
        if(on[i] && st == -1) st = i;
        if(on[i]) ed = i;
    }
    if(st == ed){
        cout << 2 << endl;
        return 0;
    }
    int res = 0;
    REP(i, n){
        if(on[i]){
            if(S[i+1] == T[i]){
                int fl = 0;
                for(int j = i+1; j <= ed; j++){
                    if(S[j] != T[j-1]){
                        fl = 1;
                        break;
                    }
                }
                res += 1-fl;
            }
            if(S[i] == T[i+1]) {
                int fl = 0;
                for(int j = i+1; j <= ed; j++){
                    if(S[j-1] != T[j]){
                        fl = 1;
                        break;
                    }
                }
                res += 1 - fl;
            }
            break;
        }
    }
    cout << res << endl;
}