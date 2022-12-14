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

vector < int > vc[100001], vp[100001];
pair < int, int > pp[100001];
int match[100001], vis[100001];
int dfs(int c, int p1){
    vis[c] = 1;
    match[p1] = -1;
    int last = 0;
    REP(i, vc[c].size()){
        if(vis[vc[c][i]]) {
            if(match[vp[c][i]] != 0) continue;
            int p = vp[c][i];
            if(last == 0 && p) last = p;
            else if(last && p){
                match[last] = p;
                match[p] = last;
                last = 0;
            }
            continue;
        }
        int p = dfs(vc[c][i], vp[c][i]);
        if(last == 0 && p) last = p;
        else if(last && p){
            match[last] = p;
            match[p] = last;
            last = 0;
        }
    }
    if(last && p1) {
        match[last] = p1;
        match[p1] = last;
        last = 0;
    } else if(last == 0)last = p1;
    return last;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b;
    FOR(i, 1, b + 1){
        cin >> pp[i].xx >> pp[i].yy;
        vc[pp[i].xx].pb(pp[i].yy);
        vc[pp[i].yy].pb(pp[i].xx);
        vp[pp[i].xx].pb(i);
        vp[pp[i].yy].pb(i);
    }
    FOR(i, 1, a + 1){
        if(vis[i] == 0) {
            c = dfs(i, 0);
            if(c != 0){
                cout << "No solution" << endl;
                return 0;
            }
        }
    }
    FOR(i, 1, b + 1){
        if(match[i] > i) continue;
        if(pp[i].xx == pp[match[i]].xx){
            cout << pp[i].yy << " " << pp[i].xx << " " << pp[match[i]].yy << endl;
        } else if(pp[i].xx == pp[match[i]].yy){
            cout << pp[i].yy << " " << pp[i].xx << " " << pp[match[i]].xx << endl;
        } else if(pp[i].yy == pp[match[i]].xx){
            cout << pp[i].xx << " " << pp[i].yy << " " << pp[match[i]].yy << endl;
        } else {
            cout << pp[i].xx << " " << pp[i].yy << " " << pp[match[i]].xx << endl;
        }
    }
}