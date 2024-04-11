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

vector < pair < LL, LL > > G[100001], tmp;
LL ar[100001];
map < LL, LL > mm;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a;
    FOR(i, 1, a + 1){
        cin >> ar[i];
        G[i].pb(mp(ar[i], 1));
        if(i == 1){
            mm[ar[i]]++;
            continue;
        }
        REP(j, G[i - 1].size()){
            b = gcd(G[i - 1][j].xx, ar[i]);
            G[i].pb(mp(b, G[i - 1][j].yy));
        }
        tmp.clear();
        vsort(G[i]);
        REP(j, G[i].size()){
            if(j > 0 && G[i][j - 1].xx == G[i][j].xx) continue;
            for(int k = j + 1; k < G[i].size(); k++){
                if(G[i][k].xx == G[i][j].xx) G[i][j].yy += G[i][k].yy;
                else break;
            }
            tmp.pb(G[i][j]);
        }
        REP(j, tmp.size()) mm[tmp[j].xx] += tmp[j].yy;
        G[i].clear();
        G[i] = tmp;
    }
    cin >> b;
    REP(i, b){
        cin >> c;
        cout << mm[c] << endl;
    }
}