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

string pp[4] = {
    "123",
    "456",
    "789",
    "#0#"
};

int ar[11];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; string s; cin >> n >> s;
    REP(i, 10) ar[i] = i;
    FOR(i, 1, s.size()){
        int p = s[i-1] - '0', q = s[i] - '0';
        int x1, y1, x2, y2;
        REP(j, 4){
            REP(k, 3){
                if(pp[j][k]-'0' == p) {
                    x1 = j; y1 = k;
                }
                if(pp[j][k]-'0' == q){
                    x2 = j; y2 = k;
                }
            }
        }

        REP(j, 10){
            if(ar[j] == -1) continue;
            int x3, y3;
            REP(k, 4){
                REP(l, 3){
                    if(pp[k][l]-'0' == ar[j]){
                        x3 = k; y3 = l;
                    }
                }
            }

            x3 += x2 - x1;
            y3 += y2 - y1;
            if(x3 < 0 || x3 > 3 || y3 < 0 || y3 > 2 || pp[x3][y3] == '#'){
                ar[j] = -1;
                continue;
            }
            ar[j] = pp[x3][y3] - '0';
        }
    }
    int cnt = 0;
    REP(i, 10) if(ar[i] != -1) cnt++;
    if(cnt == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}