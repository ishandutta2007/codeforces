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

LL ar[200005][2], dis[200005], height[200005];
LL seg[800001][2][2], id[800001][2][2];
void insert(int idx, int s, int e, int p){
    if(s == e){
        REP(i, 2){
            seg[idx][i][0] = ar[s][i];
            id[idx][i][0] = s;
        }
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p);
    else if(p > mid) insert(idx * 2 + 2, mid + 1, e, p);
    REP(i, 2){
        seg[idx][i][0] = seg[idx * 2 + 1][i][0]; id[idx][i][0] = id[idx * 2 + 1][i][0];
        seg[idx][i][1] = seg[idx * 2 + 1][i][1]; id[idx][i][1] = id[idx * 2 + 1][i][1];
        if(seg[idx * 2 + 2][i][0] > seg[idx][i][0]){
            seg[idx][i][1] = seg[idx][i][0];
            id[idx][i][1] = seg[idx][i][0];
            seg[idx][i][0] = seg[idx * 2 + 2][i][0];
            id[idx][i][0] = id[idx * 2 + 2][i][0];
        } else if(seg[idx * 2 + 2][i][0] > seg[idx][i][1]){
            seg[idx][i][1] = seg[idx * 2 + 2][i][0];
            id[idx][i][1] = id[idx * 2 + 2][i][0];
        }
        if(seg[idx * 2 + 2][i][1] > seg[idx][i][1]){
            seg[idx][i][1] = seg[idx * 2 + 2][i][1];
            id[idx][i][1] = id[idx * 2 + 2][i][1];
        }
    }
}
LL qq[2][2], qid[2][2];
void query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed){
        REP(i, 2){
            if(seg[idx][i][0] > qq[i][0]){
                qq[i][1] = qq[i][0];
                qid[i][1] = qid[i][0];
                qq[i][0] = seg[idx][i][0];
                qid[i][0] = id[idx][i][0];
            } else if(seg[idx][i][0] > qq[i][1]){
                qq[i][1] = seg[idx][i][0];
                qid[i][1] = id[idx][i][0];
            }
            if(seg[idx][i][1] > qq[i][1]){
                qq[i][1] = seg[idx][i][1];
                qid[i][1] = id[idx][i][1];
            }
        }
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        query(idx * 2 + 1, s, mid, st, mid);
        query(idx * 2 + 2, mid + 1, e, mid + 1, ed);

    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    REP(i, 8*n) REP(j, 2) REP(k, 2)seg[i][j][k] = -(1ll<<52);
    FOR(i, 1, n + 1) {
        cin >> dis[i + 1];
        dis[i + n + 1] = dis[i + 1];
    }
    FOR(i, 1, n + 1){
        cin >> height[i];
        height[i + n] = height[i];
    }
    for(int i = 1; i <= n+n; i++){
        dis[i] += dis[i - 1];
        ar[i][0] = height[i]*2ll - dis[i];
        ar[i][1] = height[i]*2ll + dis[i];
        insert(0, 1, n+n, i);
    }
    REP(ts, m){
        int a, b;
        cin >> a >> b;
        if(a > b)b += n;
        int l = b + 1, r = a + n - 1;
        REP(i, 2) REP(j, 2) qq[i][j] = -(1ll<<52);
        query(0, 1, n+n, l, r);
        LL res = 0;
        REP(i, 2){
            REP(j, 2){
                if(qid[0][i] != qid[1][j]) res = max(res, qq[0][i]+qq[1][j]);
            }
        }
        cout << res << "\n";
    }
}