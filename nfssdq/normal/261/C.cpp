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
#define ALL(A)     A.begin(), A.end()
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

LL ncr[51][51];
LL go(LL n, LL b){
    vector < int > vc;
    while(n > 0){
        vc.pb(n%2);
        n /= 2;
    }
    reverse(ALL(vc));
    LL ret = 0;
    REP(i, vc.size()){
        if(b < 0) break;
        if(vc[i] == 1){
            ret += ncr[vc.size() - i - 1][b];
            b--;
        }
    }
    if(b == 0) ret++;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    ncr[0][0] = 1;
    for(int i = 1; i <= 50; i++){
        ncr[i][0] = 1;
        for(int j = 1; j <= i; j++) ncr[i][j] = ncr[i-1][j - 1] + ncr[i-1][j];
    }
    cin >> a >> b;
    b *= -1;
    REP(i, 50){
        if(-b == 1ll<<i) {
            b = i+1;
            break;
        }
    }
    if(b <= 0 || b >= 50){
        cout << 0 << endl;
        return 0;
    }
    f = go(a + 1, b);
    if(b == 1) f--;
    cout << f << endl;
}