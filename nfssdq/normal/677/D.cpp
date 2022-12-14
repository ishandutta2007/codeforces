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

int seg[4][301 * 4];
multiset < int > ms[4][301];
vector < int > vc[2][301];
vector < pair < int, int > > vp[301 * 301];
void insert(int f, int idx, int s, int e, int p, int v){
    if(s == e){
        seg[f][idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(f, idx * 2 + 1, s, mid, p, v);
    else insert(f, idx * 2 + 2, mid + 1, e, p, v);
    seg[f][idx] = min(seg[f][idx * 2 + 1], seg[f][idx * 2 + 2]);
}
int query(int f, int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return seg[f][idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(f, idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(f, idx * 2 + 2, mid + 1, e, st, ed);
    else return min(query(f, idx * 2 + 1, s, mid, st, mid), query(f, idx * 2 + 2, mid + 1, e, mid + 1, ed));
}

int ar[301][301], res[301][301];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, p; cin >> n >> m >> p;
	FOR(i, 1, n+1){
        FOR(j, 1, m+1){
            int x; cin >> x;
            vp[x].pb(mp(i, j));
            ar[i][j] = x;
        }
	}

    FOR(j, 1, m+1) REP(k, 4) ms[k][j].insert(mod);

	for(int i = p-1; i >= 1; i--){
        setinf(seg);
        FOR(j, 1, n+1) vc[0][j].clear(), vc[1][j].clear();
        REP(j, vp[i+1].size()){
            vc[0][ vp[i+1][j].xx ].pb( vp[i+1][j].yy );
        }
        REP(j, vp[i].size()){
            vc[1][ vp[i][j].xx ].pb(vp[i][j].yy);
        }
        for(int j = 1; j <= n; j++){
            for(int k = 0; k < vc[0][j].size(); k++){
                ms[2][ vc[0][j][k] ].insert(res[j][ vc[0][j][k] ] + j - vc[0][j][k]);
                insert(2, 0, 1, m, vc[0][j][k], (*ms[2][ vc[0][j][k] ].begin()));
                ms[3][ vc[0][j][k] ].insert(res[j][ vc[0][j][k] ] + j + vc[0][j][k]);
                insert(3, 0, 1, m, vc[0][j][k], (*ms[3][ vc[0][j][k] ].begin()));
            }
        }

        for(int j = 1; j <= n; j++){
            for(int k = 0; k < vc[0][j].size(); k++){
//                if(i == 6) cout << res[j][ vc[0][j][k] ] - j + vc[0][j][k] << endl;
                insert(0, 0, 1, m, vc[0][j][k], res[j][ vc[0][j][k] ] - j - vc[0][j][k]);
                insert(1, 0, 1, m, vc[0][j][k], res[j][ vc[0][j][k] ] - j + vc[0][j][k]);

                int vx = res[j][ vc[0][j][k] ] + j, vy = vc[0][j][k];
                ms[2][vy].erase(ms[2][vy].find(vx - vy));
                insert(2, 0, 1, m, vc[0][j][k], (*ms[2][vy].begin()));
                ms[3][vy].erase(ms[3][vy].find(vx + vy));
                insert(3, 0, 1, m, vc[0][j][k], (*ms[3][vy].begin()));
            }
            for(int k = 0; k < vc[1][j].size(); k++){
                int x = j, y = vc[1][j][k];
                res[x][y] = mod;
                res[x][y] = min(res[x][y], x+y+query(0, 0, 1, m, 1, y));
                res[x][y] = min(res[x][y], x-y+query(1, 0, 1, m, y, m));
//                if(i == 6) cout << res[x][y] << endl;
                res[x][y] = min(res[x][y], -x+y+query(2, 0, 1, m, 1, y));
                res[x][y] = min(res[x][y], -x-y+query(3, 0, 1, m, y, m));
            }
        }
	}

//	FOR(i, 1, n+1){
//        FOR(j, 1, m+1) cout << res[i][j] << " ";
//        cout << endl;
//	}

	int ans = mod;
	FOR(i, 1, n+1){
        FOR(j, 1, m+1){
            if(ar[i][j] == 1) ans = min(ans, abs(i-1)+abs(j-1)+res[i][j]);
        }
	}
	cout << ans << endl;
}