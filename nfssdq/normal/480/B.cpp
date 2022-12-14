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

LL ar[100001];
set < int > s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b >> x >> y;
    REP(i, a){
        cin >> ar[i];
        s.insert(ar[i]);
    }
    f = g = 0;
    for(int i = 0; i < a; i++){
        if(s.count(ar[i] - x) || s.count(ar[i] + x)) f =1 ;
        if(s.count(ar[i] - y) || s.count(ar[i] + y)) g =1 ;
    }
    if(f && g){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < a; i++){
        c = ar[i] - x;
        if(c >= 0){
            if(s.count(c - y) || s.count(c + y) || g){
                cout << 1 << endl;
                cout << ar[i] - x << endl;
                return 0;
            }
        }
        c = ar[i] + x;
        if(c <= b){
            if(s.count(c - y) || s.count(c + y) || g){
                cout << 1 << endl;
                cout << ar[i] + x << endl;
                return 0;
            }
        }
        c = ar[i] - y;
        if(c >= 0){
            if(s.count(c - x) || s.count(c + x) || f){
                cout << 1 << endl;
                cout << ar[i] - y << endl;
                return 0;
            }
        }
        c = ar[i] + y;
        if(c <= b){
            if(s.count(c - x) || s.count(c + x) || f){
                cout << 1 << endl;
                cout << ar[i] + y << endl;
                return 0;
            }
        }
    }
    cout << 2 << endl;
    cout << x << " " << y << endl;
}