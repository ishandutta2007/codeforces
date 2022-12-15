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

vector < pair < int, pair < int, int > > > vc[2];
vector < pair < int, int > > coordinate[2][100011];
int ar[2][100011], n, m;
void print(int x, int y, int f){
    REP(i, x){
        int len = 0;
        REP(j, coordinate[0][i].size()) len += coordinate[0][i][j].yy;
        if((len^f) < len){
            cout << ar[0][i] << " 0 ";
            len -= len^f;
            int tmp = 0;
            REP(j, coordinate[0][i].size()){
                if(tmp + coordinate[0][i][j].yy >= len){
                    len -= tmp;
                    cout << ar[0][i] << " " << coordinate[0][i][j].xx+len << endl;
                    return;
                }
                tmp += coordinate[0][i][j].yy;
            }
        }
    }
    REP(i, y){
        int len = 0;
        REP(j, coordinate[1][i].size()) len += coordinate[1][i][j].yy;
        if((len^f) < len){
            cout << "0 " << ar[1][i] << " ";
            len -= len^f;
            int tmp = 0;
            REP(j, coordinate[1][i].size()){
                if(tmp + coordinate[1][i][j].yy >= len){
                    len -= tmp;
                    cout << coordinate[1][i][j].xx+len << " " << ar[1][i] << endl;
                    return;
                }
                tmp += coordinate[1][i][j].yy;
            }
        }
    }
    cout << f << endl;
    REP(i, y){
        int len = 0;
        REP(j, coordinate[1][i].size()) len += coordinate[1][i][j].yy;
        cout << len << " " << ar[1][i] << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b >> h; n = a; m = b;
    REP(i, h){
        cin >> d >> e >> f >> g;
        if(d == f) vc[0].pb(mp(d, mp(min(e,g),max(e,g))));
        else vc[1].pb(mp(e, mp(min(d,f),max(d,f))));
    }
    vsort(vc[0]);
    vsort(vc[1]);
    c = f = 0;
    x = y = 0;
    REP(i, vc[0].size()){
        if(i == vc[0].size() - 1 || vc[0][i + 1].xx != vc[0][i].xx){
            if(vc[0][i].xx == 0 || vc[0][i].xx == a) {
                c = i + 1;
                continue;
            }
            ar[0][x] = vc[0][i].xx;
            e = g = 0;
            for(int j = c; j <= i; j++){
                if(e < vc[0][j].yy.xx){
                    coordinate[0][x].pb(mp(e, vc[0][j].yy.xx - e));
                    g += vc[0][j].yy.xx - e;
                }
                e = max(e, (LL)vc[0][j].yy.yy);
            }
            if(e < b){
                coordinate[0][x].pb(mp(e, b - e));
                g += b - e;
            }
            x++;
            f ^= g;
            c = i + 1;
        }
    }
    if((a-1-x) % 2) {
        for(int i = 1; i < a; i++){
            if(ar[0][i - 1] != i){
                ar[0][x] = i;
                coordinate[0][x].pb(mp(0, b));
                break;
            }
        }
        x++;
        f ^= b;
    }
    c = 0;
    REP(i, vc[1].size()){
        if(i == vc[1].size() - 1 || vc[1][i + 1].xx != vc[1][i].xx){
            if(vc[1][i].xx == 0 || vc[1][i].xx == b) {
                c = i + 1;
                continue;
            }
            ar[1][y] = vc[1][i].xx;
            e = g = 0;
            for(int j = c; j <= i; j++){
                if(e < vc[1][j].yy.xx){
                    coordinate[1][y].pb(mp(e, vc[1][j].yy.xx - e));
                    g += vc[1][j].yy.xx - e;
                }
                e = max(e, (LL)vc[1][j].yy.yy);
            }
            if(e < a){
                coordinate[1][y].pb(mp(e, a - e));
                g += a - e;
            }
            f ^= g;
            y++;
            c = i + 1;
        }
    }
    if((b-1-y) % 2) {
        for(int i = 1; i < b; i++){
            if(ar[1][i - 1] != i){
                ar[1][y] = i;
                coordinate[1][y].pb(mp(0, a));
                break;
            }
        }
        y++;
        f ^= a;
    }
    if(f == 0){
        cout << "SECOND" << endl;
    } else {
        cout << "FIRST" << endl;
        print(x, y, f);
    }
}
/*
5 5 10
4 3 4 0
3 5 3 4
2 4 2 3
3 3 3 0
4 4 5 4
1 2 0 2
4 3 1 3
1 1 1 3
2 3 4 3
4 1 1 1

1 2  3 1  1  2
1 1  4  1 1  4

*/