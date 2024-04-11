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


vector < int > vc;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vc.pb(0);
    string s;
    while(cin >> s){
        if(s == "?") continue;
        if(s == "=") break;
        if(s == "+") vc.pb(0);
        if(s == "-") vc.pb(1);
    }

    int n; cin >> n;
    int pos = 0, neg = 0;
    REP(i, vc.size()){
        if(vc[i] == 0) pos++;
        else neg++;
    }

    if(n > 100){
        if(pos == 1 && neg > 0){
            cout << "Impossible" << endl;
            return 0;
        }
        cout << "Possible" << endl;
        cout << n << " ";
        pos--;
        FOR(i, 1, vc.size()){
            if(pos < neg && vc[i] == 0){
                int v = neg-pos+1;
                cout << "+ " << v << " ";
                pos = neg;
            } else if(vc[i] == 0) {cout << "+ " << 1 << " ";}
            else if(neg < pos && vc[i] == 1){
                int v = pos-neg+1;
                cout << "- " << v << " ";
                neg = pos;
            }
            else if(vc[i] == 1) {cout << "- " << 1 << " ";}
        }
        cout << "= " << n << endl;
        return 0;
    }

    for(int i = pos; i <= pos*n; i++){
        for(int j = neg; j <= neg*n; j++){
            if(i-j != n) continue;
            cout << "Possible" << endl;
            int c1 = 0, c2 = 0;
            REP(k, vc.size()){
                if(vc[k] == 0){
                    c1++;
                    int v = i / pos;
                    if(c1 <= (i%pos)) v++;
                    if(k != 0) cout << "+ ";
                    cout << v << " ";
                } else {
                    c2++;
                    int v = j / neg;
                    if(c2 <= (j % neg)) v++;
                    cout << "- ";
                    cout << v << " ";
                }
            }
            cout << "= " << n << endl;

            return 0;
        }
    }
    cout << "Impossible" << endl;

}