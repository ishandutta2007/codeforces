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

LL cc[1000001];
LL ar[1001][1001], row[1001], col[1001];
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b >> c >> d;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++) cin >> ar[i][j];
    }
    FOR(i, 1, a + 1){
        FOR(j, 1, b + 1) row[i] += ar[i][j];
    }
    FOR(i, 1, b + 1){
        FOR(j, 1, a + 1) col[i] += ar[j][i];
    }
    priority_queue < LL > pc, pr;
    FOR(i, 1, b + 1)pc.push(col[i]);
    for(int i = 1; i <= c; i++){
        e = pc.top();
        pc.pop();
        cc[i] = cc[i - 1] + e;
        e -= d*a;
        pc.push(e);
    }
    f = cc[c];
    g = 0;
    for(int i = 0; i <= c; i++){
        if(i == 0){
            for(int j = 1; j <= a; j++) pr.push(row[j]);
            continue;
        }
        e = pr.top();
        pr.pop();
        g += e;
        pr.push(e - d*b);
        h = cc[c - i];
        h -= d*(LL)i*(LL)(c - i);
        f = max(f, g + h);
    }
    cout << f << endl;
}