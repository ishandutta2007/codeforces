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
#define linf       (1ll<<62)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M) {
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b) {if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M) {return bigmod(a,M-2,M);}

LL bit[41][41][41][41];
void insert(int x1, int y1, int x2, int y2){
    for(int i = x1; i <= 40; i += i & -i){
        for(int j = y1; j <= 40; j += j & -j){
            for(int k = x2; k <= 40; k += k & -k){
                for(int l = y2; l <= 40; l += l & -l){
                    bit[i][j][k][l]++;
                }
            }
        }
    }
}
LL query(int x1, int y1, int x2, int y2){
    LL ret = 0;
    for(int i = x1; i > 0; i -= i & -i){
        for(int j = y1; j > 0; j -= j & -j){
            for(int k = x2; k > 0; k -= k & -k){
                for(int l = y2; l > 0; l -= l & -l){
                    ret += bit[i][j][k][l];
                }
            }
        }
    }
    return ret;
}
char pp[41][41];
LL ar[41][41];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f,g,h = 1,x = 1,y,z = 1;
    cin >> a >> b >> c;
    REP(i, a)cin >> pp[i];
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            ar[i][j] = pp[i - 1][j - 1] - '0';
            ar[i][j] += ar[i - 1][j] + ar[i][j - 1] - ar[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            for(int k = i; k <= a; k++){
                for(int l = j; l <= b; l++){
                    d = ar[k][l] - ar[i - 1][l] - ar[k][j - 1] + ar[i - 1][j - 1];
                    if(d == 0)insert(i, j, k, l);
                    if(d == 0)e++;
                }
            }
        }
    }
    REP(i, c){
        cin >> e >> f >> g >> h;
        cout << query(g, h, g, h) - query(e - 1, h, g, h) - query(g, f - 1, g, h) + query(e - 1, f - 1, g, h) << endl;
    }
}