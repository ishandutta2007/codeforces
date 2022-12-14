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
#define mod        777777777ll
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

LL seg[400001][4][4], ar[100001], mat[4][4];
void build(int idx, int s, int e){
    if(s == e){
        FOR(i, 1, 4) seg[idx][i][i] = 1;
        return;
    }
    int mid = (s + e) / 2;
    build(idx * 2 + 1, s, mid);
    build(idx * 2 + 2, mid + 1, e);
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            for(int k = 1; k <= 3; k++){
                for(int l = 1; l <= 3; l++){
                    if(mat[k][l] == 1)
                        seg[idx][i][j] = (seg[idx][i][j] + seg[idx * 2 + 1][i][k]*seg[idx * 2 + 2][l][j]) % mod;
                }
            }
        }
    }
}
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        FOR(i, 1, 4) seg[idx][i][i] = 0;
        if(v == 0){
            FOR(i, 1, 4) seg[idx][i][i] = 1;
        } else seg[idx][v][v] = 1;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    int l0 = 1, r0 = 3, l1 = 1, r1 = 3;
    if(ar[s] != 0) l0 = r0 = ar[s];
    if(ar[e] != 0) l1 = r1 = ar[e];
    int lm = 1, rm = 3, lm1 = 1, rm1= 3;
    if(ar[mid] != 0) lm = rm = ar[mid];
    if(ar[mid + 1] != 0) lm1 = rm1 = ar[mid + 1];
    FOR(i, 1, 4) FOR(j, 1, 4) seg[idx][i][j] = 0;
    for(int i = l0; i <= r0; i++){
        for(int j = l1; j <= r1; j++){
            for(int k = lm; k <= rm; k++){
                for(int l = lm1; l <= rm1; l++){
                     if(mat[k][l] == 1)
                        seg[idx][i][j] = (seg[idx][i][j] + seg[idx * 2 + 1][i][k]*seg[idx * 2 + 2][l][j]) % mod;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b;
    FOR(i, 1, 4) FOR(j, 1, 4) cin >> mat[i][j];
    build(0, 1, a);
    REP(i, b){
        cin >> c >> d;
        ar[c] = d;
        insert(0, 1, a, c, d);
        int l0 = 1, r0 = 3, l1 = 1, r1 = 3;
        if(ar[1] != 0) l0 = r0 = ar[1];
        if(ar[a] != 0) l1 = r1 = ar[a];
        c = 0;
        for(int j = l0; j <= r0; j++){
            for(int k = l1; k <= r1; k++){
                c = (c + seg[0][j][k]) % mod;
            }
        }
        cout << c << endl;
    }
}