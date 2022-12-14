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

typedef pair<LL, int> pil;

vector<int>vc[100001], id[100001];
int vis[100001], isBridge[100001];
int cnt,in[100001],val[100001];
void dfs(int v,int p)
{
	vis[v] = 1;
	in[v] = val[v] = cnt++;
	REP(i, vc[v].size())
    {
		if(vc[v][i] == p)continue;
		if(vis[vc[v][i]])val[v] = min(val[v], in[vc[v][i]]);
		else{
			dfs(vc[v][i], v);
			val[v] = min(val[v], val[vc[v][i]]);
			if (val[vc[v][i]] > in[v]){
                isBridge[id[v][i]] = 1;
            }
		}
	}
}

vector < int > vc_f[100001], vp_f[100001], id_f[100001];
vector < int > vc_r[100001], vp_r[100001];
int edge[100001][3];
LL dis_f[100001], dis_r[100001];

map < pair<int,int>, int > mm;

priority_queue < pil, vector < pil >, greater < pil > > pq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, s, t; cin >> n >> m >> s >> t;
    REP(i, m){
        int x, y, w; cin >> x >> y >> w;
        vc_f[x].pb(y); vc_r[y].pb(x); id_f[x].pb(i);
        vp_f[x].pb(w); vp_r[y].pb(w);
        edge[i][0] = x; edge[i][1] = y; edge[i][2] = w;

        if(mm[ mp(x,y) ] == 0) mm[ mp(x,y) ] = w;
        else if(abs(mm[ mp(x,y) ]) > w) mm[ mp(x,y) ] = w;
        else if(abs(mm[ mp(x,y) ]) == w){
            if(mm[ mp(x,y) ] == w) mm[ mp(x,y) ] = -w;
        }
    }

    pq.push(mp(0, s));
    setinf(dis_f);
    dis_f[s] = 0;
    while(!pq.empty()){
        pil pp = pq.top();
        pq.pop();

        if(pp.xx > dis_f[pp.yy]) continue;

        REP(i, vc_f[pp.yy].size()){
            int c = vc_f[pp.yy][i];
            if(dis_f[c] > pp.xx + vp_f[pp.yy][i]){
                dis_f[c] = pp.xx + vp_f[pp.yy][i];
                pq.push(mp(dis_f[c], c));
            }
        }
    }

    pq.push(mp(0, t));
    setinf(dis_r);
    dis_r[t] = 0;
    while(!pq.empty()){
        pil pp = pq.top();
        pq.pop();

        if(pp.xx > dis_r[pp.yy]) continue;

        REP(i, vc_r[pp.yy].size()){
            int c = vc_r[pp.yy][i];
            if(dis_r[c] > pp.xx + vp_r[pp.yy][i]){
                dis_r[c] = pp.xx + vp_r[pp.yy][i];
                pq.push(mp(dis_r[c], c));
            }
        }
    }

//    FOR(i, 1, n + 1) cout << dis_f[i] << " " << dis_r[i] << endl;

    queue < int > Q;
    Q.push(s);
    set0(vis);
    while(!Q.empty()){
        int c = Q.front();
        Q.pop();

        REP(i, vc_f[c].size()){
            if(dis_r[ vc_f[c][i] ] + vp_f[c][i] == dis_r[c]){
                if(vis[ vc_f[c][i] ] == 0) Q.push(vc_f[c][i]);
                vis[ vc_f[c][i] ] = 1;

                int p = vc_f[c][i];
                vc[c].pb(p); id[c].pb( id_f[c][i] );
                vc[p].pb(c); id[p].pb( id_f[c][i] );
//                cout << c << " " << p << endl;
            }
        }
    }

    set0(vis);
    dfs(s, 0);

    LL sp = dis_f[t];

    REP(i, m){
//        cout << isBridge[i] << endl;
        LL x = edge[i][0], y = edge[i][1], w = edge[i][2];
        if(isBridge[i] && mm[ mp(x,y) ] > 0) cout << "YES" << endl;
        else if(dis_f[x] + dis_r[y] + 1ll < sp){
            LL v = sp - dis_f[x] - dis_r[y] - 1;
            if(w-v >= 1) cout << "CAN " << w - v << endl;
            else cout << "NO" << endl;
        } else cout << "NO" << endl;
    }
}