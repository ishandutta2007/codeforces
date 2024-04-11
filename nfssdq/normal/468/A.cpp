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


void print1(int n){
    cout << "YES" << endl;
    int a = 1;
    for(int i = 2; i < 24; i += 2){
        cout << i + 1 << " - " << i << " = 1" << endl;
        a++;
    }
    for(int i = 25; i < (n - (n%2)); i += 2){
        cout << i + 1 << " - " << i << " = 1" << endl;
        a++;
    }
    if(n % 2 == 1){
        a -= 2;
        cout << "1 - 1 = 0" << endl;
        cout << n << " * 0 = 0" << endl;
        cout << "1 + 0 = 1" << endl;
    }
    REP(i, a) cout << "24 * 1 = 24" << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    if(a >= 24){
        print1(a);
    } else {
        if(a <= 3) {
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        if(a % 2 == 1){
            b = 0;
            for(int i = 6; i < a; i += 2){
                cout << i+1 << " - " << i << " = 1" << endl;
                b++;
            }
            cout << "2 - 1 = 1" << endl;
            cout << "5 - 1 = 4" << endl;
            cout << "4 + 4 = 8" << endl;
            cout << "8 * 3 = 24" << endl;
            REP(i, b) cout << "24 * 1 = 24" << endl;
            return 0;
        }
        else {
            b = 0;
            for(int i = 5; i < a; i += 2){
                cout << i+1 << " - " << i << " = 1" << endl;
                b++;
            }
            b++;
            cout << "4 * 2 = 8" << endl;
            cout << "8 * 3 = 24" << endl;
            REP(i, b) cout << "24 * 1 = 24" << endl;
        }
    }
}