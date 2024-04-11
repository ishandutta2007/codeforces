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

int ar[5][1001][1001];
void insert(int d, int c, int p){
    ar[d][c][p] = 1;
}
int query(int d, int c, int p){
    return ar[d][c][p];
}
char pp[444][444];
int pre[2][444][444];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f = 0,g,h = 0,x = 0,y,z;
    cin >> a >> b;
    REP(i, a) cin >> pp[i];
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++) if(pp[i - 1][j - 1] == '1') insert(0, i, j);
    }
    for(int j = 1; j <= b; j++){
        for(int i = 1; i <= a; i++) if(pp[i - 1][j - 1] == '1') insert(1, j, i);
    }
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i - 1 < 1 || j + 1 > b) pre[0][i][j] = 1;
            else pre[0][i][j] = pre[0][i - 1][j + 1] + 1;
            if(pp[i - 1][j - 1] == '1')
                insert(2, i+j, pre[0][i][j]);
        }
    }
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i - 1 < 1 || j - 1 < 1) pre[1][i][j] = 1;
            else pre[1][i][j] = pre[1][i - 1][j - 1] + 1;
            if(pp[i - 1][j - 1] == '1')
                insert(3, i-j + 400, pre[1][i][j]);
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 1000; j++){
            for(int k = 1; k <= 1000; k++) ar[i][j][k] += ar[i][j][k - 1];
        }
    }

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            for(int k = j + 1; k <= b; k++){
                c = query(0, i, k) - query(0, i, j - 1);
                if(c > 0) continue;

                d = i + k - j; if(d > a) goto e1;
                c = query(1, j, d) - query(1, j, i - 1);
                if(c > 0) goto e1;
                c = query(2, i+k, pre[0][d][j]) - query(2, i+k, pre[0][i][k]-1);
                if(c == 0) f++;

                e1:

                d = i - k + j; if(d < 1) goto e2;
                c = query(1, j, i) - query(1, j, d - 1);
                if(c > 0) goto e2;
                c = query(3, i-k+400, pre[1][i][k]) - query(3, i-k+400, pre[1][d][j]-1);
                if(c == 0) f++;

                e2:

                d = i + k - j; if(d > a) goto e3;
                c = query(1, k, d) - query(1, k, i - 1);
                if(c > 0) goto e3;
                c = query(3, i-j+400, pre[1][d][k]) - query(3, i-j+400, pre[1][i][j]-1);
                if(c == 0) f++;

                e3:

                d = i - k + j; if(d < 1) goto e4;
                c = query(1, k, i) - query(1, k, d - 1);
                if(c > 0) goto e4;
                c = query(2, i+j, pre[0][i][j]) - query(2, i+j, pre[0][d][k]-1);
                if(c == 0) f++;

                e4:

                if((k - j) % 2 != 0) continue;
                e = (k + j) / 2;
                d = i - e + j; if(d < 1) goto e5;
                c = query(2, i+j, pre[0][i][j]) - query(2, i+j, pre[0][d][e] - 1);
                if(c > 0) goto e5;
                c = query(3, i-k+400, pre[1][i][k]) - query(3, i-k+400, pre[1][d][e] - 1);
                if(c == 0) f++;

                e5:

                d = i + e - j; if(d > a) continue;
                c = query(3, i-j+400, pre[1][d][e]) - query(3, i-j+400, pre[1][i][j] - 1);
                if(c > 0) continue;
                c = query(2, i+k, pre[0][d][e]) - query(2, i+k, pre[0][i][k] - 1);
                if(c == 0) f++;
            }
        }
    }

    for(int i = 1; i <= b; i++){
        for(int j = 1; j <= a; j++){
            for(int k = j + 1; k <= a; k++){
                c = query(1, i, k) - query(1, i, j - 1);
                if(c > 0 || (k - j) % 2 != 0) continue;

                d = (j + k) / 2;
                e = i - d + j; if(e < 1) goto p1;
                c = query(2, i+j, pre[0][d][e]) - query(2, i+j, pre[0][j][i] - 1);
                if(c > 0) goto p1;
                c = query(3, k-i+400, pre[1][k][i]) - query(3, k-i+400, pre[1][d][e] - 1);
                if(c == 0) f++;

                p1:

                e = i + d - j; if(e > b) continue;
                c = query(3, j-i+400, pre[1][d][e]) - query(3, j-i+400, pre[1][j][i] - 1);
                if(c > 0) continue;
                c = query(2, d+e, pre[0][k][i]) - query(2, d+e, pre[0][d][e] - 1);
                if(c == 0) f++;
            }
        }
    }
    cout << f << endl;
}