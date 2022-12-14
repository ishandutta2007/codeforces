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

int pre[200001];
int Find(int x){
    if(x == pre[x]) return x;
    return pre[x] = Find(pre[x]);
}
int seg[800001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = (seg[idx * 2 + 1] + seg[idx * 2 + 2]);
}
int query(int idx, int s, int e, int st, int ed){
    if(seg[idx] == 0) return -1;
    if(s == e){
        if(seg[idx]) return s;
        return -1;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        int v = query(idx * 2 + 1, s, mid, st, mid);
        if(v == -1) return query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    FOR(i, 1, n + 1){
        pre[i] = i;
        if(i > 1)insert(0, 1, n, i, 1);
    }
    while(q--){
        int t, x, y; cin >> t >> x >> y;
        if(t == 1){
            int px = Find(x), py = Find(y);
            if(px == py) continue;
            pre[px] = py;

        } else if(t == 2){
            int p = Find(x);

            int lo = x + 1;
            while(lo <= y){
                int v = query(0, 1, n, lo, y);
                if(v == -1) break;
                insert(0, 1, n, v, 0);
                pre[Find(v)] = p;
                lo = v + 1;
            }

        } else {
            if(Find(x) == Find(y)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}