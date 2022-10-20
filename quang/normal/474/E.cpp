#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010;

typedef pair<int, int> pi;

int n;
long long d;
int sl[N], t[N];
long long h[N];
vector <long long> q;
pi a[N * 4];

void Push(int node, int l, int r, int id, int sl, int vt) {
    if(l > id || r < id) return;
    if(l == r) {
        a[node] = max(a[node], make_pair(sl, vt));
        return;
    }
    int m = (l + r) / 2;
    Push(node * 2, l, m, id, sl, vt);
    Push(node * 2 + 1, m + 1, r, id, sl, vt);
    a[node] = max(a[node * 2], a[node * 2 + 1]);
}

pi Getmax(int node, int l, int r, int x, int y) {
    if(x > r || l > y) return make_pair(-1, -1);
    if(x <= l && r <= y) return a[node];
    int m = (l + r) / 2;
    pi p1 = Getmax(node * 2, l, m, x, y);
    pi p2 = Getmax(node * 2 + 1, m + 1, r, x, y);
    return max(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> h[i], q.push_back(h[i]);
    q.push_back(-100000000000000000ll);
    q.push_back(100000000000000000ll);
    sort(q.begin(), q.end());
    int vt = lower_bound(q.begin(), q.end(), h[1]) - q.begin();
    sl[1] = 1;
    Push(1, 0, n + 1, vt, 1, 1);
    for(int i = 2; i <= n; i++) {
        int vt = lower_bound(q.begin(), q.end(), h[i]) - q.begin();
        int vt1 = upper_bound(q.begin(), q.end(), h[i] - d) - q.begin() - 1;
        int vt2 = lower_bound(q.begin(), q.end(), h[i] + d) - q.begin();
        pi res = max(Getmax(1, 0, n + 1, 0, vt1), Getmax(1, 0, n + 1, vt2, n + 1));
        sl[i] = res.first + 1;
        t[i] = res.second;
        Push(1, 0, n + 1, vt, sl[i], i);
    }
    vt = 0;
    int gtmax = -1;
    for(int i = 1; i <= n; i++)
    if(gtmax < sl[i]) {
        gtmax = sl[i];
        vt = i;
    }
    cout << gtmax << endl;
    vector <int> ans;
    while(vt) {
        ans.push_back(vt);
        vt = t[vt];
    }
    for(int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
    return 0;
}