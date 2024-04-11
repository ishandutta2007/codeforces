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

set < int > S[100001];
vector < int > pX[100001], vc;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    REP(i, a){
        cin >> b >> c;
        pX[b].pb(c);
        S[b].insert(c);
    }
    REP(i, 100001){
        vsort(pX[i]);
        if(pX[i].size() > 300) continue;
        REP(j, pX[i].size()){
            REP(k, j){
                b = pX[i][j] - pX[i][k];
                if(i-b >= 0 && S[i-b].count(pX[i][k]) && S[i-b].count(pX[i][j])) f++;
                if(i+b > 100000) continue;
                if(pX[i+b].size() <= 300) continue;
                if(S[i+b].count(pX[i][k]) && S[i+b].count(pX[i][j])) f++;
            }
        }
    }
    REP(i, 100001){
        if(pX[i].size() > 300) {
            vc.pb(i);
            continue;
        }
    }
    REP(i, vc.size()){
        REP(j, i){
            b = vc[i] - vc[j];
            REP(k, pX[ vc[i] ].size()){
                if(S[vc[i]].count(pX[ vc[i] ][k] - b) &&
                   S[vc[j]].count(pX[ vc[i] ][k] - b) && S[vc[j]].count(pX[ vc[i] ][k]) )
                        f++;

            }
        }
    }
    cout << f << endl;

}