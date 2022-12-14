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

LL n, s;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f,g,h = 0,x = 1,y,z;
    cin >> n >> s;
    if(s > n*9 || (s == 0 && n > 1)){
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    if(s == 0){
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    b = s;
    for(int i = 0; i < n; i++){
        a = (n - i - 1) * 9;
        if(a >= b){
            if(i == 0) {
                cout << 1;
                b--;
            }
            else cout << 0;
        } else {
            cout << b-a;
            b = a;
        }
    }
    cout << " ";
    b = s;
    for(int i = 0; i < n; i++){
        if(b == 0){
            cout << 0;
            continue;
        }
        if(b <= 9) {
            cout << b;
            b = 0;
        } else {
            cout << 9;
            b -= 9;
        }
    }
    cout << endl;
}