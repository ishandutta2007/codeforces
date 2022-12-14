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

int seg[2000001][2], lzy[2000001], fib[200001], M;
void update(int idx, int s, int e){
    if(s == e){
        lzy[idx] = 0;
        return;
    }
    int v1 = (seg[idx*2+1][0]*fib[lzy[idx]-1] + seg[idx*2+1][1]*fib[lzy[idx]]) % M;
    int v2 = (seg[idx*2+1][0]*fib[lzy[idx]] + seg[idx*2+1][1]*fib[lzy[idx]+1]) % M;
    seg[idx*2+1][0] = v1;
    seg[idx*2+1][1] = v2;
    lzy[idx * 2 + 1] += lzy[idx];

    v1 = (seg[idx*2+2][0]*fib[lzy[idx]-1] + seg[idx*2+2][1]*fib[lzy[idx]]) % M;
    v2 = (seg[idx*2+2][0]*fib[lzy[idx]] + seg[idx*2+2][1]*fib[lzy[idx]+1]) % M;
    seg[idx*2+2][0] = v1;
    seg[idx*2+2][1] = v2;
    lzy[idx * 2 + 2] += lzy[idx];

    lzy[idx] = 0;
}
void insert1(int idx, int s, int e, int p, int v1, int v2){
    if(lzy[idx]){
        update(idx, s, e);
    }
    if(s == e){
//        cout << s << " " << v1 << " " << v2 << endl;
        seg[idx][0] = v1;
        seg[idx][1] = v2;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert1(idx * 2 + 1, s, mid, p, v1, v2);
    else insert1(idx * 2 + 2, mid + 1, e, p, v1, v2);
    REP(i, 2) seg[idx][i] = (seg[idx*2+1][i] + seg[idx*2+2][i]) % M;
}
void insert2(int idx, int s, int e, int st, int ed){
    if(st > ed) return;
    if(lzy[idx]){
        update(idx, s, e);
    }
    if(s == st && e == ed){
        int v = (seg[idx][0] + seg[idx][1]) % M;
        seg[idx][0] = seg[idx][1];
        seg[idx][1] = v;
        lzy[idx]++;
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) insert2(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) insert2(idx * 2 + 2, mid + 1, e, st, ed);
    else{
        insert2(idx * 2 + 1, s, mid, st, mid);
        insert2(idx * 2 + 2, mid + 1, e, mid + 1, ed);
    }
    REP(i, 2) seg[idx][i] = (seg[idx*2+1][i] + seg[idx*2+2][i]) % M;
}
pair<int,int> query1(int idx, int s, int e, int st, int ed){
    if(lzy[idx]){
        update(idx, s, e);
    }
    if(st > ed) return mp(0,0);
    if(s == st && e == ed) return mp(seg[idx][0], seg[idx][1]);
    int mid = (s + e) / 2;
    if(ed <= mid) return query1(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query1(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        pair<int,int> pl = query1(idx * 2 + 1, s, mid, st, mid);
        pair<int,int> pr = query1(idx * 2 + 2, mid + 1, e, mid + 1, ed);
        return mp((pl.xx+pr.xx)%M, (pl.yy+pr.yy)%M);
    }
}

int seg2[2000001];
void insert(int idx, int s, int e, int p){
    if(s == e){
        seg2[idx]++;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p);
    else insert(idx * 2 + 2, mid + 1, e, p);
    seg2[idx]++;
}
int query(int idx, int s, int e, int st, int ed){
    if(st > ed) return 0;
    if(s == st && e == ed) return seg2[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        return query(idx * 2 + 1, s, mid, st, mid) +
               query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
    }
}

pair < int, int > pp[300001];
vector < pair<int,int> > vc[300001];
int res[300001];
map < int, int > mm;
int ar[300001], val[300001];

int on[300001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n >> M;
    REP(i, n){
        cin >> ar[i];
        mm[ar[i]] = 1;
    }
    int cnt = 0;
    for(auto &v: mm) {
        v.yy = ++cnt;
        val[v.yy] = v.xx % M;
    }

    REP(i, n){
        ar[i] = mm[ar[i]];
    }

    fib[0] = 0; fib[1] = 1%M;
    for(int i = 2; i <= 200000; i++) fib[i] = (fib[i-1] + fib[i-2]) % M;


    int SZ = 230;

    int q; cin >> q;
    REP(i, q){
        int l, r; cin >> l >> r; l--; r--;
        pp[i] = mp(l, r);

        if((l/SZ) == (r/SZ)){
            set<int> S;
            for(int j = l; j <= r; j++) S.insert(ar[j]);
            int cc = 0;
            for(auto &v: S){
                res[i] = (res[i] + val[v] * fib[++cc]) % M;
            }
            continue;
        }

        vc[r].pb(mp(l, i));
    }


    for(int i = 0; i < n; i += SZ){
        set0(on); set0(seg); set0(seg2);
        for(int j = i+SZ; j < n; j++){
            if(on[ar[j]] == 0){
                on[ar[j]] = 1;
                int pre = query(0, 1, cnt, 1, ar[j]-1) + 1;
                insert(0, 1, cnt, ar[j]);

                insert1(0, 1, cnt, ar[j], (val[ar[j]]*fib[pre-1])%M, (val[ar[j]]*fib[pre])%M);
                insert2(0, 1, cnt, ar[j]+1, cnt);
            }
            REP(k, vc[j].size()){
                if(vc[j][k].xx < i || vc[j][k].xx >= i+SZ) continue;

                set < int > S;
                for(int l = i+SZ-1; l >= vc[j][k].xx; l--){
                    if(on[ar[l]] || S.count(ar[l])) continue;
                    S.insert(ar[l]);
                }

                int cc = 0, pre = 0, tot = 0;
                for(auto &v: S){
                    pair<int,int> p = query1(0, 1, cnt, pre+1, v);
                    int pcnt = query(0, 1, cnt, pre+1, v);

                    int vv = (p.xx*fib[cc] + p.yy*fib[cc+1]) % M;

                    pre = v;
                    tot += pcnt + 1;
                    cc++;

                    vv = (vv + val[v]*fib[tot]) % M;

//                    cout << p.xx << " " << p.yy << " " << vv << " " << cc << endl;
                    res[vc[j][k].yy] = (res[vc[j][k].yy] + vv) % M;

                }
                pair<int,int> p = query1(0, 1, cnt, pre+1, cnt);

                int vv = (p.xx*fib[cc] + p.yy*fib[cc+1]) % M;
//                cout << p.xx << " " << p.yy << " " << vv << " " << cc << endl;
                res[vc[j][k].yy] = (res[vc[j][k].yy] + vv) % M;

            }

        }
    }

    REP(i, q) cout << res[i] << "\n";
}
/*
5 10
2 2 3 1 0
1
2 4

1 2 3
1 2 3
*/