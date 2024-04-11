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

#define MX 22
LL MODSQ = mod*mod;
LL mul_res[MX][MX];
void multiply(LL a[][MX], LL b[][MX]){
    set0(mul_res);
    for(int i = 0; i < MX; i++){
        for(int j = 0; j < MX; j++){
            for(int k = 0; k < MX; k++){
                mul_res[i][j] = (mul_res[i][j] + a[i][k] * b[k][j]);
        		if(mul_res[i][j] >= MODSQ) mul_res[i][j] -= MODSQ;
        	}
        	mul_res[i][j] %= mod;
        }
    }
}

LL big_res[MX][MX];
LL init[MX][MX];
void matrix_expo(LL n){
    if(n == 0){
        set0(big_res);
        REP(i, MX)big_res[i][i] = 1;
        return;
    }
    if(n % 2 == 0){
        matrix_expo(n / 2);
        multiply(big_res, big_res);
        REP(i, MX){
            REP(j, MX)big_res[i][j] = mul_res[i][j];
        }
    }
    else {
        matrix_expo(n - 1);
        multiply(big_res, init);
        REP(i, MX){
            REP(j, MX)big_res[i][j] = mul_res[i][j];
        }
    }
}


int ar[22][22];
LL mat_last[22][22];
int nxt[5][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1}, {0, 0} };
int id[22][22];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    int cc = 0;
    REP(i, n) REP(j, m) id[i][j] = cc++;

    set0(init);
    REP(i, n){
        REP(j, m){
            if(ar[i][j]) continue;
            REP(k, 5){
                int nx = (i + nxt[k][0]);
                int ny = (j + nxt[k][1]);
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || ar[nx][ny]) continue;
                init[ id[i][j] ][ id[nx][ny] ] = 1;
            }
        }
    }
    REP(i, cc) mat_last[i][i] = 1;

    int last = 1;
    while(q--){
        int t, x, y, v; cin >> t >> x >> y >> v;
        x--; y--;
        if(t == 1){
            matrix_expo(v - last );
            multiply(mat_last, big_res);
            last = v ;
            REP(i, cc) REP(j, cc) mat_last[i][j] = mul_res[i][j];
            cout << mat_last[0][id[x][y]] << endl;
            last = v;
        } else if(t == 2){
            ar[x][y] = 1;
            matrix_expo(v - last - 1);
            multiply(mat_last, big_res);
            REP(i, cc) REP(j, cc) mat_last[i][j] = mul_res[i][j];
            last = v - 1;

            set0(init);
            REP(i, n){
                REP(j, m){
                    REP(k, 5){
                        int nx = (i + nxt[k][0]);
                        int ny = (j + nxt[k][1]);
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m || ar[nx][ny]) continue;
                        init[ id[i][j] ][ id[nx][ny] ] = 1;
                    }
                }
            }

        } else {
            ar[x][y] = 0;
            matrix_expo(v - last);
            multiply(mat_last, big_res);
            REP(i, cc) REP(j, cc) mat_last[i][j] = mul_res[i][j];
            last = v;

            set0(init);
            REP(i, n){
                REP(j, m){
                    REP(k, 5){
                        int nx = (i + nxt[k][0]);
                        int ny = (j + nxt[k][1]);
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m || ar[nx][ny]) continue;
                        init[ id[i][j] ][ id[nx][ny] ] = 1;
                    }
                }
            }
        }

//        REP(i, cc){
//            REP(j, cc) cout << mat_last[i][j] << " ";
//            cout << endl;
//        }
//
//        REP(i, cc){
//            REP(j, cc) cout << big_res[i][j] << " ";
//            cout << endl;
//        }

    }
}