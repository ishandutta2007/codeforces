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

vector < int > vc[100001];
pair < int, pair < int, int > > pp[100001];
int vis[100001], last[100001], cc;
vector < int > sm[100001];
unordered_set<int>bg[1001];
void dfs(int c, int p){
    last[cc++] = c;
    vis[c] = p;
    REP(i, vc[c].size()){
        if(vis[vc[c][i]] != p) dfs(vc[c][i], p);
    }
}
int main() {
    ios_base:: sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b;
    REP(i, b){
        cin >> pp[i].yy.xx >> pp[i].yy.yy >> pp[i].xx;
    }
    sort(pp, pp + b);
    REP(i, b){
        for(int j = i; j < b; j++){
            if(pp[j].xx != pp[i].xx) break;
            vc[ pp[j].yy.xx ].clear();
            vc[ pp[j].yy.yy ].clear();
        }
        for(int j = i; j < b; j++){
            if(pp[j].xx != pp[i].xx) break;
            vc[ pp[j].yy.xx ].pb(pp[j].yy.yy);
            vc[ pp[j].yy.yy ].pb(pp[j].yy.xx);
        }
        for(int j = i; j < b; j++){
            if(pp[j].xx != pp[i].xx) break;
            i = j;
            if(vis[pp[j].yy.xx] != pp[j].xx){
                cc = 0;
                dfs(pp[j].yy.xx, pp[j].xx);
                if(cc >= 300){
                    for(int k = 0; k < cc; k++){
                        bg[f].insert(last[k]);
                    }
                    f++;
                } else {
                    REP(k, cc){
                        REP(l, k){
                            sm[last[k]].pb(last[l]);
                            sm[last[l]].pb(last[k]);
                        }
                    }
                }
            }
        }
    }
    FOR(i, 1, a + 1) vsort(sm[i]);
    cin >> c;
    REP(i, c){
        cin >> d >> e;
        g = upper_bound(sm[d].begin(), sm[d].end(), e) - lower_bound(sm[d].begin(), sm[d].end(), e);
        REP(j, f){
            if(bg[j].count(d) && bg[j].count(e)) g++;
        }
        cout << g << endl;
    }
}