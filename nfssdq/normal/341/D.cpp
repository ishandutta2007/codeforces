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

LL bit[2][2][1001][1001];
void insert(int px, int py, int x, int y, LL v){
    for(int i = x; i <= 1000; i += i & -i){
        for(int j = y; j <= 1000; j += j & -j) bit[px][py][i][j] ^= v;
    }
}
LL query(int px, int py, int x, int y){
    LL ret = 0;
    for(int i = x; i > 0; i -= i & -i){
        for(int j = y; j > 0; j -= j & -j) ret ^= bit[px][py][i][j];
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b;
    while(b--){
        cin >> c >> d >> e >> x >> y;
        if(c == 2){
            cin >> f;
            insert(d%2, e%2, d, e, f);
            insert((x+1)%2, e%2, x+1, e, f);
            insert(d%2, (y+1)%2, d, y+1, f);
            insert((x+1)%2, (y+1)%2, x+1, y+1, f);
        } else {
            f = 0;
            f ^= query(x%2, y%2, x, y);
            f ^= query(x%2, (e-1)%2, x, e-1);
            f ^= query((d-1)%2, y%2, d-1, y);
            f ^= query((d-1)%2, (e-1)%2, d-1, e-1);
            cout << f << endl;
        }
    }
}