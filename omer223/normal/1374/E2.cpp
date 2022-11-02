
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <memory>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;
typedef vector<vector<ll>> mat;
typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
oset;

const int sz = 2e5 + 5;
int n, m, k;
int cnt[2][2];
pll a[2][2][sz];
pll c[2][2][sz];
int revmap[2][2][sz];
pair<int, pair<pii, int>> b[sz];
oset ds;
ll fen[2 * sz];

void feninsert(int idx, ll val) {
    for (; idx < n; idx = idx | (idx + 1))
        fen[idx] += val;
}

ll fenquery(int r) {
    ll ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += fen[r];
    return ret;
}

void insert(int idx, int x, int y) {
    int aidx = c[x][y][idx].ss;
    int bidx = revmap[x][y][aidx];
    ll val = c[x][y][idx].ff;
    feninsert(bidx, val);
    ds.insert({val, bidx});
}

ll query(int topk) {
    if (!topk)return 0;
    if(ds.size() < topk)return 1e16;
    int idx = ds.find_by_order(topk - 1)->ss;
    return fenquery(idx);
}

int main() {
    fast;
    cin >> n >> m >> k;
    foru(i, 0, n) {
        ll t, x, y;
        cin >> t >> x >> y;
        a[x][y][cnt[x][y]] = {t, i};
        c[x][y][cnt[x][y]] = { t,cnt[x][y] };
        b[i] = { t,{{x,y},cnt[x][y]} };
        cnt[x][y]++;
    }
    sort(b, b + n);
    foru(x, 0, 2) {
        foru(y, 0, 2)sort(c[x][y], c[x][y] + cnt[x][y]);
    }
    foru(i, 0, n) {
        revmap[b[i].ss.ff.ff][b[i].ss.ff.ss][b[i].ss.ss] = i;
    }
    ll bst = 1e15;
    vector<int> bstidx;
    int idx = 0, aidx = 0, bidx = 0; //included
    ll prvsum = 0, asum = 0, bsum = 0;
    while (aidx < k && aidx < cnt[1][0]) {
        asum += c[1][0][aidx++].ff;
    }
    while (bidx < k && bidx < cnt[0][1]) {
        bsum += c[0][1][bidx++].ff;
    }
    ford(i, cnt[1][0] - 1, aidx)insert(i, 1, 0);
    ford(i, cnt[0][1] - 1, bidx)insert(i, 0, 1);
    foru(i, 0, cnt[0][0])insert(i, 0, 0);
    while (idx <= min(m, cnt[1][1])) {
        if (min(aidx, bidx) + idx >= k && aidx + bidx + idx <= m) {
            ll rem = query(max(0, m - (aidx + bidx + idx)));
            ll ret = rem + asum + bsum + prvsum;
            if (ret < bst) {
                bstidx = vector<int>{ idx,aidx,bidx };
                bst= ret;
            }
        }
        if (idx == min(m, cnt[1][1]))break;
        prvsum += c[1][1][idx++].ff;
        if (idx + aidx > k) {
            if (aidx != 0) {
                aidx--;
                asum -= c[1][0][aidx].ff;
                insert(aidx, 1, 0);
            }
        }
        if (idx + bidx > k) {
            if (bidx != 0) {
                bidx--;
                bsum -= c[0][1][bidx].ff;
                insert(bidx, 0, 1);
            }
        }
    }
    if(bstidx.empty()){
        cout<<-1<<'\n';
        return 0;
    }
    cout << bst << '\n';
    foru(i,0,bstidx[0]){
        int cidx = c[1][1][i].ss;
        cout<<a[1][1][cidx].ss+1<<' ';
    }
    foru(i,0,bstidx[1]){
        int cidx = c[1][0][i].ss;
        cout<<a[1][0][cidx].ss+1<<' ';
    }
    foru(i,0,bstidx[2]){
        int cidx = c[0][1][i].ss;
        cout<<a[0][1][cidx].ss+1<<' ';
    }
    int rem = m-(bstidx[0]+bstidx[1]+bstidx[2]);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    foru(i,0,cnt[0][0]){
        int cidx = c[0][0][i].ss;
        pq.push(a[0][0][cidx]);
    }
    foru(i,bstidx[1],cnt[1][0]){
        int cidx = c[1][0][i].ss;
        pq.push(a[1][0][cidx]);
    }
    foru(i,bstidx[2],cnt[0][1]){
        int cidx = c[0][1][i].ss;
        pq.push(a[0][1][cidx]);
    }
    while(rem>0){
        auto ii = pq.top();pq.pop();
        rem--;
        cout<<ii.ss+1<<' ';
    }
    cout<<'\n';
    return 0;
}