
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



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

priority_queue < LL > pq[10][2];
LL mat[10][10];
LL ar[100001];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f,g,h = 1,x,y,z;
    cin >> a >> b >> c >> d;
    FOR(i, 1, a + 1){
        FOR(j, 1, b + 1){
            cin >> e;
            f = a - i + b - j;
            g = a - i + j;
            FOR(k, 1, c + 1){
                if(pq[k][0].size() > 0)mat[e][k] = max(mat[e][k], pq[k][0].top() - f);
                if(pq[k][1].size() > 0)mat[e][k] = max(mat[e][k], pq[k][1].top() - g);
            }
            pq[e][0].push(f);
            pq[e][1].push(g);
        }
    }
    g = 0;
    REP(i, d){
        cin >> ar[i];
        if(i >= 1){
            g = max(g, mat[ar[i - 1]][ar[i]]);
            g = max(g, mat[ar[i]][ar[i - 1]]);
        }
    }
    cout << g << endl;
}