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


priority_queue < pair<LL,LL>, vector<pair<LL,LL> >, greater<pair<LL,LL> > >pq;
queue < pair < LL, LL > > Q;
pair < LL, LL > pp[200001];
LL res[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, b; cin >> n >> b;
    REP(i, n){
        cin >> pp[i].xx >> pp[i].yy;
        pq.push(mp(pp[i].xx, i));
    }
    pq.push(mp(0, -1));

    while(!pq.empty()){
        pair<LL,LL> p = pq.top(); pq.pop();
        if(p.yy == -1){
            if(Q.size() > 0){
                res[Q.front().yy] = p.xx + pp[Q.front().yy].yy;
                pq.push(mp(res[Q.front().yy], -1));
                Q.pop();
            } else {
                if(pq.size() == 0) break;
                p.xx = pq.top().xx;
                int v = pq.top().yy;
                pq.pop();
                res[v] = p.xx + pp[v].yy;
                pq.push(mp(res[v], -1));
            }
        } else {
            if(Q.size() == b) {
                res[p.yy] = -1;
            } else Q.push(p);
        }
    }

    REP(i, n) cout << res[i] << " ";
    cout << endl;
}