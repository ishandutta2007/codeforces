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

struct Euclid {
	LL x, y, d;
	Euclid() {}
	Euclid( LL xx, LL yy, LL dd ) { x = xx, y = yy, d = dd; }
};

Euclid egcd( LL a, LL b ) {
	if( !b ) return Euclid(1, 0, a);
	Euclid r = egcd ( b, a % b );
	return Euclid( r.y, r.x - a / b * r.y, r.d );
}

LL ar[1000001], br[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL m; cin >> m;
    LL h1, a1, x1, y1; cin >> h1 >> a1 >> x1 >> y1;
    LL h2, a2, x2, y2; cin >> h2 >> a2 >> x2 >> y2;

    LL a = -1, b, c = -1, d;
    for(int i = 1; i <= 3000000; i++){
        h1 = (h1 * x1 + y1) % m;
        if(h1 == a1 && ar[h1] != 0){
            a = i - ar[h1];
            b = ar[h1];
            break;
        }
        ar[h1] = i;
    }

    for(int i = 1; i <= 3000000; i++){
        h2 = (h2 * x2 + y2) % m;
        if(h2 == a2 && br[h2] != 0){
            c = i - br[h2];
            d = br[h2];
            break;
        }
        br[h2] = i;
    }
    if(ar[a1] == br[a2] && ar[a1] != 0){
        cout << ar[a1] << endl;
        return 0;
    }
    if(a == -1 && (c != -1 && ar[a1] >= d && (ar[a1]-d) % c == 0)){
        cout << ar[a1] << endl;
        return 0;
    }
    if(c == -1 && (a != -1 && br[a2] >= b && (br[a2]-b) % a == 0)){
        cout << br[a2] << endl;
        return 0;
    }
    if(a == -1 || c == -1){
        cout << -1 << endl;
        return 0;
    }
    d -= b;
    c *= -1;
    Euclid s = egcd(a, c);
    if(d % s.d){
        cout << -1 << endl;
        return 0;
    }

    d /= s.d;
    LL av = a; a /= s.d;
    LL cv = -c; c /= s.d;
    s.x *= d; s.y *= d;
//    cout << s.x << " " << s.y << endl;
    if(s.x >= 0){
        if(c < 0){
            LL v = s.x / -c;
            s.x += c*v;
            s.y -= a*v;
        } else {
            LL v = s.x / c;
            s.x -= c*v;
            s.y += a*v;
        }
    }
    while(s.x < 0){
        if(c < 0){
            LL v = s.x / c;
            s.x -= c*v;
            if(s.x < 0) {
                v++;
                s.x -= c;
            }
            s.y += a * v;
        } else {
            LL v = (-s.x) / c;
            s.x += v*c;
            if(s.x < 0){
                s.x += c;
                v++;
            }
            s.y -= v*a;
        }
    }
    while(s.y < 0){
        if(a < 0) {
            LL v = s.y / a;
            s.y -= a*v;
            if(s.y < 0){
                s.y -= a;
                v++;
            }
            s.x += v*c;
        } else {
            LL v = (-s.y) / a;
            s.y += a*v;
            if(s.y < 0){
                s.y += a;
                v++;
            }
            s.x -= v*c;
        }
    }
    if(s.x < 0 || s.y < 0){
        cout << -1 << endl;
        return 0;
    }
    cout << s.x*av + b << endl;
}