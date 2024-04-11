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

pair < int, pair < int, int > > pp[100001];
vector < int > vc[100001], vp[100001];
int dis_f[100001], dis_b[100001], vis[100001], dis[100001];
int pre[100001], id[100001], on[100001];
vector < pair < int, pair < int, int > > > out;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c=0,d,e = 0,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b;
    REP(i, b){
        cin >> c >> d >> e; e ^= 1;
        pp[i] = mp(c, mp(d, e));
        vc[c].pb(d);
        vc[d].pb(c);
        vp[c].pb(i);
        vp[d].pb(i);
    }
    deque < int > Q;
    Q.push_back(1);
    setinf(dis_f);
    dis_f[1] = 0;
    while(!Q.empty()){
        c = Q.front();
        Q.pop_front();
        if(vis[c]) continue;
        vis[c] = 1;
        REP(i, vc[c].size()){
            if(dis_f[ vc[c][i] ] > dis_f[c] + 1){
                dis_f[ vc[c][i] ] = dis_f[c] + 1;
                Q.push_back(vc[c][i]);
            }
        }
    }
    setinf(dis_b);
    set0(vis);
    Q.push_back(a);
    dis_b[a] = 0;
    while(!Q.empty()){
        c = Q.front();
        Q.pop_front();
        if(vis[c]) continue;
        vis[c] = 1;
        REP(i, vc[c].size()){
            if(dis_b[ vc[c][i] ] > dis_b[c] + 1){
                dis_b[ vc[c][i] ] = dis_b[c] + 1;
                Q.push_back(vc[c][i]);
            }
        }
    }
    set0(vis);
    setinf(dis);
    Q.pb(1);
    dis[1] = 0;
    while(!Q.empty()){
        c = Q.front();
        Q.pop_front();
        if(vis[c]) continue;
        vis[c] = 1;
        REP(i, vc[c].size()){
            if(dis_b[ vc[c][i] ] + dis_f[c] + 1 != dis_f[a]) continue;
            d = pp[ vp[c][i] ].yy.yy;
            if(dis[ vc[c][i] ] > dis[c] + d){
                dis[ vc[c][i] ] = dis[c] + d;
                pre[ vc[c][i] ] = c;
                id[ vc[c][i] ] = vp[c][i];
                if(d == 0) Q.push_front(vc[c][i]);
                else Q.push_back(vc[c][i]);
            }
        }
    }
    for(int i = a; i != 1; i = pre[i]){
        on[ id[i] ] = 1;
    }
    REP(i, b){
        if(on[i]){
            if(pp[i].yy.yy == 1) out.pb(pp[i]);
        } else {
            if(pp[i].yy.yy == 0) out.pb(pp[i]);
        }
    }
    cout << out.size() << endl;
    REP(i, out.size()){
        cout << out[i].xx << " " << out[i].yy.xx << " " << out[i].yy.yy << endl;
    }
}