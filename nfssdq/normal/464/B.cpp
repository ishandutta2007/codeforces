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


LL ar[8][3], tmp[8];
LL dis[8][8];
LL DIS(int a, int b){
    LL ret = 0;
    REP(i, 3) ret += (ar[a][i] - ar[b][i]) * (ar[a][i] - ar[b][i]);
    return ret;
}
int am[8][8];
int deg[9], vis[9];
int go(){
    REP(i, 8) REP(j, 8) dis[i][j] = DIS(i, j);
    REP(i, 8) tmp[i] = dis[0][i];
    sort(tmp, tmp + 8);
    for(int i = 1; i < 2; i++){
        set0(deg); set0(am);
        if(tmp[i] == 0) continue;
        REP(j, 8) REP(k, 8){
            if(dis[j][k] == tmp[i]){
                am[j][deg[j]++] = k;
            }
        }
        int fl = 0;
        REP(j, 8) if(deg[j] != 3) {
            fl = 1;
            break;
        }
        if(fl) continue;
        set0(vis);
        queue < int > Q;
        Q.push(0);
        vis[0] = 1;
        while(!Q.empty()){
            int a = Q.front();
            Q.pop();
            REP(j, 3){
                int b = am[a][j];
                if(vis[b] == 0){
                    vis[b] = vis[a] + 1;
                    Q.push(b);
                }
            }
        }
        int cc[8] = {0};
        REP(j, 8) {
            if(vis[j] == 0) {
                fl = 1;
                break;
            }
            cc[vis[j]]++;
        }
        if(cc[2] != 3 || cc[3] != 3 || cc[4] != 1) fl = 1;
        if(fl == 0) return 1;
    }
    return 0;
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    REP(i, 8) REP(j, 3) cin >> ar[i][j];
    sort(ar[7], ar[7] + 3);
    do{
        sort(ar[6], ar[6] + 3);
    do{
        sort(ar[5], ar[5] + 3);
    do{
        sort(ar[4], ar[4] + 3);
    do{
        sort(ar[3], ar[3] + 3);
    do{
        sort(ar[2], ar[2] + 3);
    do{
        sort(ar[1], ar[1] + 3);
    do{
        sort(ar[0], ar[0] + 3);
    do{
        if(go()){
            cout << "YES" << endl;
            REP(i, 8){
                REP(j, 3) cout << ar[i][j] << " ";
                cout << endl;
            }
            return 0;
        }
    }while(next_permutation(ar[0], ar[0] + 3));
    }while(next_permutation(ar[1], ar[1] + 3));
    }while(next_permutation(ar[2], ar[2] + 3));
    }while(next_permutation(ar[3], ar[3] + 3));
    }while(next_permutation(ar[4], ar[4] + 3));
    }while(next_permutation(ar[5], ar[5] + 3));
    }while(next_permutation(ar[6], ar[6] + 3));
    }while(next_permutation(ar[7], ar[7] + 3));

    cout << "NO" << endl;
}