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

int dp[101][9][2];
string s;
int go(int c, int m, int f){
    if(c == s.size()){
        if(f && m == 0) return 1;
        return 0;
    }
    int &ret = dp[c][m][f];
    if(ret != -1) return ret;
    ret = 0;
    ret |= go(c + 1, m, f);
    ret |= go(c + 1, ((m * 10) + s[c] - '0') % 8, 1);
    return ret;
}
void print(int c, int m, int f){
    if(c == s.size()) return;
    if(go(c + 1, m, f)) print(c + 1, m, f);
    else {
        cout << s[c];
        print(c + 1, ((m * 10) + s[c] - '0') % 8, 1);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    REP(i, s.size()){
        if(s[i] == '0'){
            cout << "YES" << endl << 0 << endl;
            return 0;
        }
    }
    memset(dp, -1, sizeof dp);
    if(go(0, 0, 0)){
        cout << "YES" << endl;
        print(0, 0, 0);
        cout << endl;
    } else cout << "NO" << endl;
}