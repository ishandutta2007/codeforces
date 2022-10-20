#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int K = sqrt(N) + 1;
const int INF = (int)1e9 + 10;
const long long INF_LL = (long long)2e18;

int q, k;
vector<int> a[N];
vector<int> moment;
int val[N];

struct Bucket {
    int cnt, firstApp, lastS;
    long long minVal, delta;

    Bucket(int cnt = 0, int firstApp = -1, int lastS = -INF, long long minVal = 0, long long delta = 0) : 
        cnt(cnt), firstApp(firstApp), lastS(lastS), minVal(minVal), delta(delta) {}

    void reset() {
        cnt = 0;
        firstApp = -1;
        lastS = -INF;
        minVal = 0;
        delta = 0;
    }

    void debug() {
        cerr << cnt << ' ' << firstApp << ' ' << lastS << ' ' << minVal << ' ' << delta << endl;
    }
} b[N / K + 10];

void init() {
    sort(moment.begin(), moment.end());
    moment.resize(unique(moment.begin(), moment.end()) - moment.begin());
    for (int i = 0; i < moment.size(); i++) val[i] = INF;
}

void updateBucket(int pos) {
    int u = pos / k;
    b[u].reset();
    int curS = 0;
    for (int i = k * u; i < min(k * (u + 1), (int)moment.size() - 1); i++) {
        if (val[i] == INF) {
            b[u].delta += 1ll * curS * (moment[i + 1] - moment[i]);
        } else {
            b[u].cnt++;
            if (b[u].firstApp == -1) b[u].firstApp = i;
            curS = val[i];
            b[u].delta += 1ll * curS * (moment[i + 1] - moment[i]);
        }
        b[u].minVal = min(b[u].minVal, b[u].delta);
    }
    b[u].lastS = curS;
}

bool go(long long &v, int &curS, int l, int r, double &res) {
    for (int i = l; i < r; i++) {
        if (val[i] != INF) curS = val[i];
        if (v + 1ll * curS * (moment[i + 1] - moment[i]) <= 0ll) {
            res = -(double)v / curS + moment[i];
            return 1;
        }
        v += 1ll * curS * (moment[i + 1] - moment[i]);
    }
    return 0;
}

double getRes(int l, int r, long long v) {
    l = lower_bound(moment.begin(), moment.end(), l) - moment.begin();
    r = lower_bound(moment.begin(), moment.end(), r) - moment.begin();
    if (v == 0) return moment[l];
    if (moment.size() == 1) {
        return -1;
    }
    r--;
    int ll = l / k;
    int rr = r / k;
    if (ll == rr) {
        int curS = 0;
        double res = -1;
        if (go(v, curS, l, r + 1, res)) return res;
        else return -1;
    }
    int curS = 0;
    double res = -1;
    if (go(v, curS, l, min(k * (ll + 1), (int)moment.size() - 1), res)) return res;
    for (int i = ll + 1; i < rr; i++) {
        if (b[i].cnt == 0) {
            int fullTime = moment[k * (i + 1)] - moment[k * i];
            if (v + 1ll * curS * fullTime <= 0) return -(double)v / curS + moment[k * i];
            v += 1ll * curS * fullTime;
            continue;
        }
        int foo = moment[b[i].firstApp] - moment[i * k];
        if (v + 1ll * curS * foo <= 0ll) {
            return -(double)v / curS + moment[i * k];
        }
        v += 1ll * curS * foo;
        if (v + b[i].minVal <= 0) {
            if (go(v, curS, b[i].firstApp, min(k * (i + 1), (int)moment.size() - 1), res)) return res;
        } else {
            v += b[i].delta;
            curS = b[i].lastS;
        }
    }
    if (go(v, curS, k * rr, r + 1, res)) return res;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int op;
        cin >> op;
        a[i].push_back(op);
        if (op == 1) {
            int t, s;
            cin >> t >> s;
            moment.push_back(t);
            a[i].push_back(t);
            a[i].push_back(s);
        } else if (op == 2) {
            int t;
            cin >> t;
            moment.push_back(t);
            a[i].push_back(t);
        } else {
            int l, r, v;
            cin >> l >> r >> v;
            moment.push_back(l);
            moment.push_back(r);
            a[i].push_back(l);
            a[i].push_back(r);
            a[i].push_back(v);
        }
    }
    init();
    k = sqrt(moment.size()) + 1;

    for (int i = 1; i <= q; i++) {
        if (a[i][0] == 1) {
            int pos = lower_bound(moment.begin(), moment.end(), a[i][1]) - moment.begin();
            val[pos] = a[i][2];
            updateBucket(pos);
        } else if (a[i][0] == 2) {
            int pos = lower_bound(moment.begin(), moment.end(), a[i][1]) - moment.begin();
            val[pos] = INF;
            updateBucket(pos);
        } else {
            double ans = getRes(a[i][1], a[i][2], a[i][3]);
            if (ans < 0) cout << -1 << '\n';
            else cout << fixed << setprecision(10) << ans << '\n';
        }
        // cerr << "q " << i << ' ' << endl;
        // for (int i = 0; i < (int)moment.size() / k; i++) {
        //     cerr << "number " <<  i << ' ' ;
        //     b[i].debug();
        // }
    }
    return 0;
}