#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#define mod 1000000007
using namespace std;

int n, m, l[100005], r[100005], q[100005], cur, lis[100005];
vector<pair<int, pair<int, int> > > v;
int cnt[30];
int sl[500005], sr[500005], seg[500005];

void process(int t, int num) {
    if (!t) {
        for (int i = 0; i < 30; i++) if (num & (1 << i)) {
            if (!cnt[i]) cur += (1 << i);
            cnt[i]++;
        }
    } else {
        for (int i = 0; i < 30; i++) if (num & (1 << i)) {
            cnt[i]--;
            if (!cnt[i]) cur -= (1 << i);
        }
    }
}

void sayYes() {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << lis[i] << ' ';
}

void construct(int node) {
    if (sl[node] == sr[node]) seg[node] = lis[sl[node]];
    else {
        int mid = (sl[node] + sr[node]) / 2;
        sl[node * 2] = sl[node];
        sr[node * 2] = mid;
        sl[node * 2 + 1] = mid + 1;
        sr[node * 2 + 1] = sr[node];
        construct(node * 2);
        construct(node * 2 + 1);
        seg[node] = seg[node * 2] & seg[node * 2 + 1];
    }
}

int getSeg(int ql, int qr, int node) {
    if (ql <= sl[node] && qr >= sr[node]) return seg[node];
    if (ql > sr[node] || qr < sl[node]) return ((1 << 30) - 1);
    return getSeg(ql, qr, node * 2) & getSeg(ql, qr, node * 2 + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> q[i];
        l[i]--;
        r[i]--;
        v.push_back({l[i], {0, q[i]}});
        v.push_back({r[i] + 1, {1, q[i]}});
    }
    sort(v.begin(), v.end());
    int p = 0;
    for (int i = 0; i < n; i++) {
        while (p < 2 * m && v[p].first <= i) {
            process(v[p].second.first, v[p].second.second);
            p++;
        }
        lis[i] = cur;
    }
    sl[1] = 0;
    sr[1] = n - 1;
    construct(1);
    for (int i = 0; i < m; i++) {
        if (getSeg(l[i], r[i], 1) != q[i]) {
//            if (n == 1000) {
//                cout << getSeg(l[i], r[i], 1) << endl;
//                cout << l[i] << ' ' << r[i] << ' ' << q[i] << endl;
//                sayYes();
//            }
            cout << "NO";
            return 0;
        }
    }
    sayYes();
}