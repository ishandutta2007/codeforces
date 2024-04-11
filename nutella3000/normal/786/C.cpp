#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double

const int inf = 1e15;
const int max_n = (1 << 17);

int sum[2 * max_n];


void upd(int id, int v = 1, int l = 0, int r = max_n - 1, int num = 0) {
    if (l > id || r < id) return;
    if (l == id && r == id) {
        sum[v] = num;
        return;
    }
    int m = (l + r) / 2;
    upd(id, v * 2, l, m, num);
    upd(id, v * 2 + 1, m + 1, r, num);
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
}

void build(vector<int> a) {
    for(int i = 0;i < sz(a);i++) {
        upd(i, 1, 0, max_n - 1, a[i]);
    }
}

int get(int left, int &cnt, int v = 1, int l = 0, int r = max_n - 1) {
    if (r < left) return -1;

    int num = r - l + 1 - sum[v];

    if (l >= left && num <= cnt) {
        cnt -= num;
        return r;
    }

    if (l == r) {
        cnt -= num;
        return -1;
    }

    int m = (l + r) / 2;

    int r1, r2 = -1;
    r1 = get(left, cnt, v * 2, l, m);

    if (cnt >= 0)
        r2 = get(left, cnt, v * 2 + 1, m + 1, r);

    return max(r1, r2);

}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) 
        cin >> a[i];

    vector<int> last(n + 1, inf);
    vector<int> nxt(n);
    vector<int> temp(n);
    for(int i = n - 1;i >= 0;i--) {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }
    for(int i = 0;i < n;i++) {
        if (nxt[i] < n) temp[nxt[i]] = 1;
    }

    //cout << "bef build" << endl;

    build(temp);
    //cout << "after build" << endl;

    vector<deque<pii>> req(n + 1);

    for(int i = n;i >= 1;i--)
        req[0].emplace_back(i, 0);

    for(int i = 0;i < n;i++) {
        while(sz(req[i])) {
            pii v = req[i].back();
            req[i].pop_back();
            v.se++;

            int cnt = v.fi;

            //cout << "bef " << i << " " << v.fi << endl;
            int temp = get(i, cnt) + 1;
            req[min(n, temp)].emplace_back(v);

            //cout << i << " " << v.fi << " " << temp << endl;
            //cout << "aft " << i << " " << v.fi << endl; 
        }

        if (nxt[i] < n) upd(nxt[i]);
    }

    vector<int> res(n);
    for(auto i : req[n]) {
        res[i.fi - 1] = i.se;
    }

    for(int i : res)
        cout << i << " ";
}
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}