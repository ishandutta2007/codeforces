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

char pp[1002][1002], tmp[1001][1001];
int go(int x, int y, int b, int c, int a, int d){
    REP(i, a) REP(j, d) tmp[i][j] = pp[i][j];
    for(int i = b; i < b + x; i++){
        for(int j = c; j < c + y; j++){
            if(tmp[i][j] == '.'){
                return 0;
            }
            tmp[i][j] = '.';
        }
    }
    while(1){
        if(b+x != a && tmp[b+x][c] == 'X'){
            b++;
            for(int j = c; j < c + y; j++){
                if(tmp[b+x-1][j] == '.'){
                    return 0;
                }
                tmp[b+x-1][j] = '.';
            }
        } else if(c+y != d && tmp[b][c + y] == 'X'){
            c++;
            for(int i = b; i < b + x; i++){
                if(tmp[i][c+y-1] == '.'){
                    return 0;
                }
                tmp[i][c + y - 1] = '.';
            }
        } else break;
    }
    REP(i, a){
        REP(j, d) {
            if(tmp[i][j] == 'X'){
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> d;
    REP(i, a) cin >> pp[i];
    REP(i, a){
        REP(j, d){
            if(pp[i][j] == 'X'){
                b = i;
                c = j;
                goto ps;
            }
        }
    }
    ps:
    for(int i = b; i < a; i++){
        if(pp[i][c] == '.') break;
        x++;
    }
    for(int i = c; i < d; i++){
        if(pp[b][i] == '.') break;
        y++;
    }
    for(int i = b + 1; i < a; i++){
        f = 0;
        for(int j = 0; j < d; j++)
            if(pp[i - 1][j] == pp[i][j] && pp[i][j] == 'X') f++;
        if(f == 0) break;
        y = min(y, f);
    }
    for(int j = c + 1; j < d; j++){
        f = 0;
        for(int i = 0; i < a; i++){
            if(pp[i][j - 1] == pp[i][j] && pp[i][j] == 'X') f++;
        }
        if(f == 0) break;
        x = min(x, f);
    }
    if( x <= 0 || y <= 0){
        cout << -1 << endl;
        return 0;
    }
    f = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < d; j++){
            if((i < b || i >= x+b || j < c  || j >= c+y) && pp[i][j] == 'X')f = 1;
        }
    }
    if(f == 0){
        cout << min(x,y) << endl;
        return 0;
    }
    f = 100000000;
    for(int i = x; i >= max(1ll, x - 400); i--){
        if(go(i,y,b,c,a,d)) {
            f = min(f, (LL)i*y);
            break;
        }
    }

    for(int i = y; i >= max(1ll, y - 400); i--){
        if(go(x,i,b,c,a,d)) {
            f = min(f, (LL)i*x);
            break;
        }
    }
    if(f > x*y) cout << -1 << endl;
    else cout << f << endl;
}
/*
6 6
..XXX.
..XXX.
..XXXX
..XXXX
...XXX
...XXX
*/