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
#define PI         2.0*acos(0.0)
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

LL ar[1005][1005], nxt[5][1005][1005];
LL tmp[1005];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b >> h;
    FOR(i, 1, a + 1){
        FOR(j, 1, b + 1){
            cin >> ar[i][j];
        }
    }
    FOR(j, 1, b + 1) nxt[0][1][j] = ar[1][j];
    FOR(i, 2, a + 1){
        FOR(j, 1, b + 1){
            if(ar[i][j] == 0) nxt[0][i][j] = 0;
            else nxt[0][i][j] = 1 + nxt[0][i - 1][j];
        }
    }
    FOR(j, 1, b + 1) nxt[1][a][j] = ar[a][j];
    for(int i = a - 1; i >= 1; i--){
        FOR(j, 1, b + 1){
            if(ar[i][j] == 0) nxt[1][i][j] = 0;
            else nxt[1][i][j] = 1 + nxt[1][i + 1][j];
        }
    }
    FOR(i, 1, a + 1) nxt[2][i][1] = ar[i][1];
    FOR(i, 2, b + 1){
        FOR(j, 1, a + 1){
            if(ar[j][i] == 0) nxt[2][j][i] = 0;
            else nxt[2][j][i] = 1 + nxt[2][j][i - 1];
        }
    }
    FOR(i, 1, a + 1) nxt[3][i][b] = ar[i][b];
    for(int i = b - 1; i >= 1; i--){
        FOR(j, 1, a + 1){
            if(ar[j][i] == 0) nxt[3][j][i] = 0;
            else nxt[3][j][i] = 1 + nxt[3][j][i + 1];
        }
    }
//    FOR(i, 1, a + 1){
//        FOR(j, 1, b + 1) {
//            REP(k, 4) cout << nxt[k][i][j] << " ";
//            cout << endl;
//        }
//    }
//    stack < pair < int, int > > S;
    REP(ts, h){
        cin >> x >> e >> f;
        if(x == 1){
            ar[e][f] ^= 1;
            for(int i = e; i <= a; i++){
                if(ar[i][f] == 0) nxt[0][i][f] = 0;
                else nxt[0][i][f] = 1 + nxt[0][i - 1][f];
            }
            for(int i = e; i >= 1; i--){
                if(ar[i][f] == 0) nxt[1][i][f] = 0;
                else nxt[1][i][f] = 1 + nxt[1][i + 1][f];
            }
            for(int i = f; i <= b; i++){
                if(ar[e][i] == 0) nxt[2][e][i] = 0;
                else nxt[2][e][i] = 1 + nxt[2][e][i - 1];
            }
            for(int i = f; i >= 1; i--){
                if(ar[e][i] == 0) nxt[3][e][i] = 0;
                else nxt[3][e][i] = 1 + nxt[3][e][i + 1];
            }
        } else {
            g = 0;

            tmp[f] = nxt[0][e][f];
            for(int i = f - 1; i >= 1; i--){
                tmp[i] = min(tmp[i + 1], nxt[0][e][i]);
            }
            c = nxt[0][e][f];
            for(int i = f; i <= b; i++){
                c = min(c, nxt[0][e][i]);
                d = lower_bound(tmp + 1, tmp + f + 1, c) - tmp;
                g = max(g, c * (i - d + 1));
//                cout << c << " " << d << " " << i << endl;
            }
            tmp[f] = nxt[0][e][f];
            for(int i = f + 1; i <= b; i++){
                tmp[i] = min(tmp[i - 1], nxt[0][e][i]);
            }
            reverse(tmp + f, tmp + b + 1);
            c = nxt[0][e][f];
            for(int i = f; i >= 1; i--){
                c = min(c, nxt[0][e][i]);
                d = lower_bound(tmp + f, tmp + b + 1, c) - tmp;
                d = b - d + f;
                g = max(g, c * (d - i + 1));
//                cout << c << " " << g << " " << i << endl;
            }

            tmp[f] = nxt[1][e][f];
            for(int i = f - 1; i >= 1; i--){
                tmp[i] = min(tmp[i + 1], nxt[1][e][i]);
            }
            c = nxt[1][e][f];
            for(int i = f; i <= b; i++){
                c = min(c, nxt[1][e][i]);
                d = lower_bound(tmp + 1, tmp + f + 1, c) - tmp;
                g = max(g, c * (i - d + 1));
            }
            tmp[f] = nxt[1][e][f];
            for(int i = f + 1; i <= b; i++){
                tmp[i] = min(tmp[i - 1], nxt[1][e][i]);
            }
            reverse(tmp + f, tmp + b + 1);
            c = nxt[1][e][f];
            for(int i = f; i >= 1; i--){
                c = min(c, nxt[1][e][i]);
                d = lower_bound(tmp + f, tmp + b + 1, c) - tmp;
                d = b - d + f;
                g = max(g, c * (d - i + 1));
//                cout << c << " " << g << " " << i << endl;
            }

            tmp[e] = nxt[2][e][f];
            for(int i = e - 1; i >= 1; i--){
                tmp[i] = min(tmp[i + 1], nxt[2][i][f]);
            }
            c = nxt[2][e][f];
            for(int i = e; i <= a; i++){
                c = min(c, nxt[2][i][f]);
                d = lower_bound(tmp + 1, tmp + e + 1, c) - tmp;
                g = max(g, c * (i - d + 1));
            }
            tmp[e] = nxt[2][e][f];
            for(int i = e + 1; i <= a; i++){
                tmp[i] = min(tmp[i - 1], nxt[2][i][f]);
            }
            reverse(tmp + e, tmp + a + 1);
            c = nxt[2][e][f];
            for(int i = e; i >= 1; i--){
                c = min(c, nxt[2][i][f]);
                d = lower_bound(tmp + e, tmp + a + 1, c) - tmp;
                d = a - d + e;
                g = max(g, c * (d - i + 1));
//                cout << c << " " << g << " " << i << endl;
            }

            tmp[e] = nxt[3][e][f];
            for(int i = e - 1; i >= 1; i--){
                tmp[i] = min(tmp[i + 1], nxt[3][i][f]);
            }
            c = nxt[3][e][f];
            for(int i = e; i <= a; i++){
                c = min(c, nxt[3][i][f]);
                d = lower_bound(tmp + 1, tmp + e + 1, c) - tmp;
                g = max(g, c * (i - d + 1));
            }
            tmp[e] = nxt[3][e][f];
            for(int i = e + 1; i <= a; i++){
                tmp[i] = min(tmp[i - 1], nxt[3][i][f]);
            }
            reverse(tmp + e, tmp + a + 1);
            c = nxt[3][e][f];
            for(int i = e; i >= 1; i--){
                c = min(c, nxt[3][i][f]);
                d = lower_bound(tmp + e, tmp + a + 1, c) - tmp;
                d = a - d + e;
                g = max(g, c * (d - i + 1));
//                cout << c << " " << d << " " << i << endl;
            }
            cout << g << endl;
        }
    }
}