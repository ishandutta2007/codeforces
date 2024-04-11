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



vector < int > vc[100001];
LL mat[501][501], ar[100001], vis[100001];
int done[501];
void dfs(int c){
    vis[c] = 1;
    REP(i, vc[c].size()) if(!vis[vc[c][i]]) dfs(vc[c][i]);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b >> c;
    REP(i, c){
        cin >> d;
        while(d--){
            f++;
            ar[f] = i + 1;
        }
    }
    FOR(i, 1, c + 1) FOR(j, 1, c + 1){
        if(i == j)mat[i][j] = 0;
        else mat[i][j] = 100000000000ll;
    }
    REP(i, b){
        cin >> d >> e >> f;
        if(f == 0){
            vc[d].pb(e);
            vc[e].pb(d);
        } if(ar[e] != ar[d]){
            mat[ar[e]][ar[d]] = min(mat[ar[e]][ar[d]], f);
            mat[ar[d]][ar[e]] = min(mat[ar[d]][ar[e]], f);
        }
    }
    FOR(i, 1, a + 1){
        if(vis[i])continue;
        if(done[ar[i]])h = 1;
        done[ar[i]] = 1;
        dfs(i);
    }
    if(h == 1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    FOR(k, 1, c + 1){
        FOR(i, 1, c + 1){
            FOR(j, 1, c + 1)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        }
    }
    FOR(i, 1, c + 1){
        FOR(j, 1, c + 1){
            if(j != 1)cout << " ";
            if(mat[i][j] > 1000000000ll) mat[i][j] = -1;
            cout << mat[i][j];
        }
        cout << endl;
    }
}