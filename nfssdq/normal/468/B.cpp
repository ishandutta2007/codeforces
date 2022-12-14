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
LL ar[100001], deg[100001], vis[100001];
map < int, int > mm;
LL cnt, last[100001], res[100001];
void dfs(int c){
    vis[c] = 1;
    last[cnt++] = c;
    REP(i, vc[c].size()){
        int a = vc[c][i];
        if(vis[a] == 0) dfs(a);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b >> c;
    FOR(i, 1, a + 1) {
        cin >> ar[i];
        mm[ar[i]] = i;
    }
    queue < int > Q;
    FOR(i, 1, a + 1){
        d = b - ar[i];
        if(mm[d] != 0){
            vc[i].pb(mm[d]);
            vp[i].pb(0);
            deg[i]++;
        }
        d = c - ar[i];
        if(mm[d] != 0){
            vc[i].pb(mm[d]);
            vp[i].pb(1);
            deg[i]++;
        }
        if(deg[i] == 1) Q.push(i);
        if(deg[i] == 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    while(!Q.empty()){
        d = Q.front();
        Q.pop();
        if(vis[d]) continue;
        cnt = 0;
        dfs(d);
        g = 0;
        if(b - ar[last[0]] == ar[last[0]]) g = 1;
        if(b - ar[last[cnt-1]] == ar[last[cnt-1]]) g = 2;
        if(c - ar[last[0]] == ar[last[0]]) g = 3;
        if(c - ar[last[cnt-1]] == ar[last[cnt-1]]) g = 4;
        if(cnt % 2 == 1 && g == 0) {
            cout << "NO" << endl;
            return 0;
        }
        int st = 0, ed = cnt;
        if(g == 1 || g == 3){
            res[last[0]] = (g == 1) ? 1 : 2;
            st++;
        } else if(g == 2 || g == 4){
            res[last[cnt - 1]] = (g == 2) ? 1 : 2;
            ed--;
        }
        for(int i = st; i < ed; i += 2){
            REP(j, vc[last[i]].size()){
                e = vc[last[i]][j];
                if(last[i + 1] == e){
                    f = vp[last[i]][j];
                    res[last[i]] = res[last[i + 1]] = f + 1;
                }
            }
        }
    }
    FOR(t, 1, a + 1){
        if(vis[t] == 0){
            cnt = 0;
            dfs(t);
            g = 0;
            if(b - ar[last[0]] == ar[last[0]]) g = 1;
            if(b - ar[last[cnt-1]] == ar[last[cnt-1]]) g = 2;
            if(c - ar[last[0]] == ar[last[0]]) g = 3;
            if(c - ar[last[cnt-1]] == ar[last[cnt-1]]) g = 4;
            if(cnt % 2 == 1 && g == 0) {
                cout << "NO" << endl;
                return 0;
            }
            int st = 0, ed = cnt;
            if(g == 1 || g == 3) {
                res[last[0]] = (g == 1) ? 1 : 2;
                st++;
            } else if(g == 2 || g == 4) {
                res[last[cnt - 1]] = (g == 2) ? 1 : 2;
                ed--;
            }
            for(int i = st; i < ed; i += 2) {
                REP(j, vc[last[i]].size()) {
                    e = vc[last[i]][j];
                    if(last[i + 1] == e) {
                        f = vp[last[i]][j];
                        res[last[i]] = res[last[i + 1]] = f + 1;
                    }
                }
            }

        }
    }
    FOR(i, 1, a + 1){
        if(res[i] == 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    FOR(i, 1, a + 1) cout << res[i]-1 << " ";
    cout << endl;
}