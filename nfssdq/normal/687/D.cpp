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
#define mod        1000000009ll
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


int pre[1001], fl[1001];
int Find(int x){
    if(x == pre[x]) return x;
    return pre[x] = Find(pre[x]);
}

pair < pair<int,int>, pair<int,int> > pp[1000001];
int ar[1001][1001], cnt[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    FOR(i, 1, m+1) {
        cin >> pp[i].yy.xx >> pp[i].yy.yy;
        cin >> pp[i].xx.xx;
        pp[i].xx.yy = i;
    }
    sort(pp + 1, pp + m + 1);
    while(q--){
        FOR(i, 1, n+1) cnt[i] = 0;
        FOR(i, 1, n+1){
            ar[i][++cnt[i]] = i;
            pre[i] = i;
            fl[i] = 0;
        }
        int l, r; cin >> l >> r;
        int res = mod;
        for(int i = m; i >= 1; i--){
            if(pp[i].xx.yy < l || pp[i].xx.yy > r) continue;
            int x = pp[i].yy.xx, y = pp[i].yy.yy, c = pp[i].xx.xx;
            int px = Find(x), py = Find(y);
            if(px == py){
                if(fl[x] == fl[y]){
                    res = c;
                    break;
                }
            } else {
                if(cnt[px] < cnt[py]){
                    swap(px, py);
                    swap(x, y);
                }
                int d = (fl[x] == fl[y]);
                FOR(k, 1, cnt[py]+1){
                    if(d) fl[ ar[py][k] ] ^= 1;
                    ar[px][ ++cnt[px] ] = ar[py][k];
                }
                pre[py] = px;
            }
        }
        if(res == mod) cout << -1 << endl;
        else cout << res << endl;
    }
}