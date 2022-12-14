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
#define linf       (1<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
int flag = 0;
LL ar[1001][1001], n, m;
char pp[1001][1001];
string s1 = "DIMA";
string s2 = "IMAD";
int nxt[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
LL val[1001][1001], cnt = 0;
int dfs(int x, int y){
    if(ar[x][y] == 1){
        flag = 1;
        return 0;
    }
    if(ar[x][y] != 0)return val[x][y];
    int res = 0;
    ar[x][y] = 1;
    REP(i, 4){
        if(s1[i] == pp[x][y]){
            if(s1[i] == 'A')res = 1;
            REP(j, 4){
                int a = x + nxt[j][0];
                int b = y + nxt[j][1];
                if(a >= 0 && a < n && b >= 0 && b < m && pp[a][b] == s2[i]){
                    int c = dfs(a, b);
                    if(pp[a][b] == 'D')res = max(res, 1 + c);
                    else res = max(res, c);
                }
            }
        }
    }
    ar[x][y] = 2;
    return val[x][y] = res;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 1,b,c,d,e,f,g,h = 0,x,y,z;
    cin >> a >> b;
    n = a; m = b;
    REP(i, a)cin >> pp[i];
    REP(i, a){
        REP(j, b){
            if(ar[i][j] == 0 && pp[i][j] == 'D')h = max((int)h, dfs(i, j));
        }
    }
    if(flag == 1)cout << "Poor Inna!";
    else if(h == 0)cout << "Poor Dima!";
    else cout << h << endl;
}