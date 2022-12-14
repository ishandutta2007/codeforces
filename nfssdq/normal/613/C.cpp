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

int ar[27];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int gcd_val = 0, odd = 0;
    REP(i, n) {
        cin >> ar[i];
        odd += (ar[i] % 2);
        gcd_val = gcd(gcd_val, ar[i]);
    }

    if(odd > 1){
        cout << 0 << endl;
        REP(i, n){
            REP(j, ar[i]) cout << (char)('a'+i);
        }
        cout << endl;
        return 0;
    }

    string s;
    if(gcd_val % 2 == 1){
        cout << gcd_val << endl;
        REP(i, n){
            REP(j, (ar[i]/gcd_val)/2) s.pb('a'+i);
        }

        string t = s;
        reverse(s.begin(), s.end());
        REP(i, n) if((ar[i]/gcd_val) % 2 == 1) t.pb('a'+i);
        t += s;

        REP(i, gcd_val) cout << t;
        cout << endl;
    }
    else {
        cout << gcd_val << endl;
        REP(i, n){
            REP(j, (ar[i]/gcd_val)) s.pb('a'+i);
        }

        string t = s;
        reverse(s.begin(), s.end());
        t += s;

        REP(i, gcd_val/2) cout << t;
        cout << endl;
    }
}