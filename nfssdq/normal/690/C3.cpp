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


int P[200001][22], dis[200001];

int LCA(int p, int q){
    if(dis[p] < dis[q])swap(p,q);
    int log;
    for(log = 1; (1<<log) <= dis[p]; log++);
    log--;
    for(int i = log; i >= 0; i--){
        if(dis[p] - (1<<i) >= dis[q])p = P[p][i];
    }
    if(p == q)return p;
    for(int i = log; i >= 0; i--){
        if(P[p][i] != 0 && P[p][i] != P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }
    }
    return P[p][0];
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int v1 = 1, v2 = 1, d = 0;
    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        dis[i] = 1 + dis[p];
        P[i][0] = p;
        for(int j = 1; j <= 21; j++){
            P[i][j] = P[ P[i][j-1] ][j-1];
        }
        int lca1 = LCA(v1, i), lca2 = LCA(v2, i);
        int d1 = dis[i] + dis[v1] - 2*dis[lca1], d2 = dis[i] + dis[v2] - 2*dis[lca2];
        if(d1 > d){
            v2 = i;
            d = d1;
        } else if(d2 > d){
            v1 = i;
            d = d2;
        }
        cout << d << " ";
    }
    cout << endl;
}