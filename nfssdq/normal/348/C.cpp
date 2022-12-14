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

LL ar[100001];
vector < int > small[100001], large[301], sg[100001], lg[100001];
int stola[100001][301], ltol[301][301];
LL sum[301];
LL update[301], sid[100001], lid[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b >> c;
    FOR(i, 1, a + 1) cin >> ar[i];
    REP(i, b){
        cin >> d;
        if(d >= 300){
            lid[i] = g;
            sid[i] = -1;
            REP(j, d) {
                cin >> e;
                sum[g] += ar[e];
                large[g].pb(e);
                lg[e].pb(g);
            }
            g++;
        } else {
            sid[i] = h;
            lid[i] = -1;
            REP(j, d){
                cin >> e;
                small[h].pb(e);
                sg[e].pb(h);
            }
            h++;
        }
    }
    FOR(i, 1, a + 1){
        REP(j, sg[i].size()){
            REP(k, lg[i].size()){
                stola[sg[i][j]][lg[i][k]]++;
            }
        }
        REP(j, lg[i].size()){
            REP(k, lg[i].size()){
                ltol[lg[i][j]][lg[i][k]]++;
            }
        }
    }
    string s;
    REP(i, c){
        cin >> s >> d; d--;
        if(s == "?"){
            if(lid[d] >= 0){
                e = sum[lid[d]];
                REP(j, g){
                    e += update[j] * ltol[lid[d]][j];
                }
                cout << e << endl;
            } else {
                e = 0;
                REP(j, small[sid[d]].size()){
                    e += ar[small[sid[d]][j]];
                }
                REP(j, g){
                    e += update[j] * stola[sid[d]][j];
                }
                cout << e << endl;
            }
        } else {
            cin >> e;
            if(lid[d] >= 0){
                update[lid[d]] += e;
            } else {
                REP(j, small[sid[d]].size()){
                    ar[small[sid[d]][j]] += e;
                }
                REP(j, g){
                    sum[j] += e * stola[sid[d]][j];
                }
            }
        }
    }
}