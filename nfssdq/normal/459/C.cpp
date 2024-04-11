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



template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL ar[1001][1001], cnt[1001], dt;
int go(int l, int r, int b, int k, int d){
    for(int i = l; i <= r; i++) ar[d][i] = b;
    if(l == r){
        for(int i = d + 1; i <= dt; i++) ar[i][l] = b;
        return 1;
    }
    if(d >= dt) return 0;
    int a = (r - l + 1);
    if(k >= a){
        for(int i = 1; i <= a; i++){
            go(l + i-1, l+i-1, i, k, d+1);
        }
        return 1;
    }
    int bb = a % k;
    int c = a / k;
    int e = l-1, f;
    REP(i, bb){
        f = go(e + 1 , e + c + 1, i + 1, k, d + 1);
        if(f == 0) return 0;
        e += c + 1;
    }
    for(int i = bb+1; i <= k; i++){
        f = go(e + 1, e + c, i, k, d + 1);
        if(f == 0) return 0;
        e += c;
    }
    return 1;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b >> c;
    dt = c;
    d = go(1, a, 1, b, 0);
    if(d == 0) cout << -1 << endl;
    else {
        FOR(i, 1, c + 1){
            FOR(j, 1, a + 1) cout << ar[i][j] << " ";
            cout << endl;
        }
    }
}