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

int ar[9][9];
int nxt[4][2] = { { 2, 2 }, { 2, -2 }, { -2, 2 }, { -2, -2 } };

void dfs(int x, int y, int f){
    if(ar[x][y] != -1)return;
    ar[x][y] = f;
    REP(i, 4){
        int a = x + nxt[i][0];
        int b = y + nxt[i][1];
        if(a >= 0 && a < 8 && b >= 0 && b < 8)dfs(a, b, f ^ 1);
    }
}
char pp[9][9];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a, b = 0,c,d,e = 0,f,g,h = 1,x = 1,y,z;
    cin >> a;
    REP(i, a){
        REP(j, 8)cin >> pp[j];
        memset(ar, -1, sizeof ar);
        c = 0;
        REP(j, 8){
            REP(k, 8){
                if(c == 0 && pp[j][k] == 'K'){
                    dfs(j, k, 0);
                    c++;
                }
                else if(pp[j][k] == 'K'){
                    if(ar[j][k] == 0)cout << "YES" << endl;
                    else cout << "NO" << endl;
                }
            }
        }
    }
}