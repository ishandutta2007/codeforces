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

int row[1000001], col[1000001], lastRow[1000001], lastCol[1000001];
vector < vector < int > > vc, vt;
vector < int > vp1, vp2;
typedef pair<int,pair<int,int> > pp;
pp ar[1000001];

priority_queue < pp > pq;
vector < int > X[1000001], Y[1000001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, cnt = 0; cin >> n >> m;
    REP(i, n){
        vp1.clear();
        vp2.clear();
        REP(j, m){
            int x; cin >> x;
            vp1.pb(x);
            vp2.pb(-1);
            ar[cnt++] = mp(x, mp(i,j));
        }
        vc.pb(vp1);
        vt.pb(vp2);
    }

    sort(ar, ar + cnt);

    REP(i, cnt){
        pp p = ar[i];
        int v = 0;
        if(lastRow[p.yy.xx] < p.xx) v = max(v, row[p.yy.xx] + 1);
        else v = max(v, row[p.yy.xx]);
        if(lastCol[p.yy.yy] < p.xx) v = max(v, col[p.yy.yy] + 1);
        else v = max(v, col[p.yy.yy]);

        lastRow[p.yy.xx] = lastCol[p.yy.yy] = p.xx;
        row[p.yy.xx] = col[p.yy.yy] = v;

        X[p.yy.xx].pb(p.yy.yy);
        Y[p.yy.yy].pb(p.yy.xx);

        pq.push(mp(v,p.yy));

        if(!(i == cnt-1 || ar[i+1].xx != ar[i].xx)){
            continue;
        }

        while(!pq.empty()){
            p = pq.top(); pq.pop();
            if(vt[p.yy.xx][p.yy.yy] != -1) continue;
            vt[p.yy.xx][p.yy.yy] = p.xx;
            row[p.yy.xx] = p.xx;
            col[p.yy.yy] = p.xx;
            while(X[p.yy.xx].size() > 0 && vc[p.yy.xx][ X[p.yy.xx][X[p.yy.xx].size()-1] ] == ar[i].xx){
                pq.push(mp(p.xx, mp(p.yy.xx, X[p.yy.xx][X[p.yy.xx].size()-1])));
                X[p.yy.xx].pop_back();
            }
            while(Y[p.yy.yy].size() > 0 && vc[ Y[p.yy.yy][Y[p.yy.yy].size()-1] ][p.yy.yy] == ar[i].xx){
                pq.push(mp(p.xx, mp(Y[p.yy.yy][Y[p.yy.yy].size()-1], p.yy.yy)));
                Y[p.yy.yy].pop_back();
            }
        }

    }

    REP(i, n) {
        REP(j, m) cout << vt[i][j] << " ";
        cout << "\n";
    }
}