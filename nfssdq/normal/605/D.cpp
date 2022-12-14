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

int ar[100011][4];
map < int, int > mx, my;

queue < pair < int, int > > Q[300011];

int seg[1200001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}
int query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        return min(query(idx * 2 + 1, s, mid, st, mid),
                   query(idx * 2 + 2, mid + 1, e, mid + 1, ed));
    }
}
int query1(int idx, int s, int e, int st, int ed, int v){
    if(s == st && e == ed && seg[idx] != v) return -1;
    if(s == e) return s;
    int mid = (s + e) / 2;
    if(ed <= mid) return query1(idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid) return query1(idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        int lft = query1(idx * 2 + 1, s, mid, st, mid, v);
        if(lft == -1) return query1(idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
        else return lft;
    }
}

queue < int > qq;
int dis[100011], pre[100011];
vector < int > res;
vector < pair < int, int > > vp[300001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n){
        REP(j, 4) cin >> ar[i][j];
        mx[ ar[i][0] ] = mx[ ar[i][2] ] = 1;
        my[ ar[i][1] ] = my[ ar[i][3] ] = 1;
    }
    ar[n][0] = ar[n][1] = ar[n][2] = ar[n][3] = 0;
    mx[0] = 1; my[0] = 1;
    int cc = 0;
    for(auto &v: mx){
        v.yy = ++cc;
    }
    cc = 0;
    for(auto &v: my){
        v.yy = ++cc;
    }

    REP(i, n+1){
        ar[i][0] = mx[ar[i][0]];
        ar[i][1] = my[ar[i][1]];
        ar[i][2] = mx[ar[i][2]];
        ar[i][3] = my[ar[i][3]];
        if(i != n) vp[ ar[i][0] ].push_back(mp( ar[i][1], i ));
    }


    int len = 250000;
    for(int i = 1; i <= len; i++) {
        vsort(vp[i]);

        REP(j, vp[i].size()){
            Q[i].push(vp[i][j]);
        }

        if(Q[i].size() == 0) insert(0, 1, len, i, inf);
        else insert(0, 1, len, i, Q[i].front().xx);
    }

    REP(i, n+1) dis[i] = 10000000;
    dis[n] = 0;
    qq.push(n);


    while(!qq.empty()){
        int c = qq.front(); qq.pop();
//        cout << "ppppppp" << c << " " << ar[c][2] << endl;
        while(1){
            int mx = query(0, 1, len, 1, ar[c][2]);
            if(mx > ar[c][3]) break;
            int pos = query1(0, 1, len, 1, ar[c][2], mx);
//            cout << Q[pos].front().yy << " " << c << endl;


            dis[ Q[pos].front().yy ] = 1 + dis[c];
            qq.push(Q[pos].front().yy);
            pre[ Q[pos].front().yy ] = c;
            Q[pos].pop();



            if(Q[pos].size() == 0) insert(0, 1, len, pos, inf);
            else insert(0, 1, len, pos, Q[pos].front().xx);
//            cout << c << " " << mx << " " << pos << " " << Q[pos].size() << endl;
        }
    }


    if(dis[n-1] > n+1) cout << -1 << endl;
    else {
        cout << dis[n-1] << endl;
        int st = n-1;
        while(st != n){
            res.pb(st);
            st = pre[st];
        }

        for(int i = res.size() - 1; i >= 0; i--) cout << res[i]+1 << " ";
        cout << endl;
    }

}