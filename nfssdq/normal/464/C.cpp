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

string to[100001][10];
LL len[100011][10], md[100011][10];
string s, s1;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> s;
    cin >> a;
    REP(i, a){
        cin >> s1;
        b = s1[0] - '0';
        for(int j = 0; j < 10; j++) to[i][j] = (char)(j + '0');
        to[i][b] = "";
        for(int j = 3; j < s1.size(); j++) to[i][b] += s1[j];
    }
    REP(i, 10) {
        len[a][i] = 1;
        md[a][i] = i;
    }
    for(int i = a - 1; i >= 0; i--){
        REP(j, 10){
            for(int k = 0; k < to[i][j].size(); k++){
                b = to[i][j][k] - '0';
                len[i][j] = (len[i][j] + len[i + 1][b]) % (mod - 1);
                md[i][j] = (md[i][j] * bigmod(10ll, len[i + 1][b], mod)) % mod;
                md[i][j] = (md[i][j] + md[i + 1][b]) % mod;
            }
        }
    }
    f = 0;
    REP(i, s.size()){
        b = s[i] - '0';
        f = (f * bigmod(10ll, len[0][b], mod));
        f = (f + md[0][b]) % mod;
    }
    cout << f << endl;
}