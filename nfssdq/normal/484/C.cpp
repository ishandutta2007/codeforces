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


string s;
int ar[1000001], vis[1000001], id[1000001], pos[1000001];
pair < int, int > pp[1000001];
vector < int > cycles[1000001];
int last[1000001], cc, line[1000001], rev[1000001];
void dfs(int c, int p){
    vis[c] = 1;
    last[p] = c;
    if(ar[c] == 0) return;
    if(ar[c] == last[0]){
        cc++;
        REP(i, p + 1){
            cycles[cc].pb(last[i]);
            id[last[i]] = cc;
            pos[last[i]] = i;
        }
        return;
    }
    if(vis[ar[c]]) return;
    dfs(ar[c], p + 1);
}
char out[1000001];
int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> s;
    cin >> a;
    REP(ts, a){
        cin >> b >> c;
        REP(i, b) pp[i] = mp(i%c, i);
        sort(pp, pp + b);
        REP(i, b) rev[i] = 0;
        REP(i, b) {
            ar[pp[i].yy] = i - 1;
            if(i > 0) rev[i - 1] = pp[i].yy;
        }
        REP(i, b){
            id[i] = 0;
            vis[i] = 0;
            cycles[i + 1].clear();
        }
        cc = 0;
        FOR(i, 1, b){
            if(vis[i] == 0) dfs(i, 0);
        }
        g = 0;
        line[g++] = 0;
        for(int i = rev[0]; i != 0; i = rev[i]){
            pos[i] = g;
            line[g++] = i;
        }
        FOR(i, 1, s.size()){
            if(i < b) {
                d = i;
                e = s.size() - b + 1;
                f = 0;
            }
            else {
                d = b - 1;
                e = s.size() - i;
                f = i - b + 1;
            }
            if(id[d] == 0){
                if(pos[d] <= e){
                    out[f + pos[d]] = s[i];
                } else {
                    out[s.size() - b + 1 + line[ pos[d] - e ] ] = s[i];
                }
            } else {
                out[ s.size() - b + 1 + cycles[ id[d] ][ (pos[d] + e) % cycles[id[d]].size() ] ] = s[i];
            }
        }
//        cout << out[4] << endl;
        FOR(i, 1, s.size()) s[i] = out[i];
        cout << s << "\n";
    }
}
/*
ABCDEFGHI
4
5 3
6 4
4 2
7 5

-1 1 3 0 2
 0 1 2 3 4


ADCEFGBIH
AFECGDHIB
AECGDHIFB
AHDGEBFIC

*/