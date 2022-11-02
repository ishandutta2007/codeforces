#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 1e15;
const int max_n = 2001;

int n, k;
pii per[max_n];
int a[max_n];

void f1(int l, int r, vector<int>& p0, vector<int>& p1, vector<int>& p2) {
    if (r < l) return;
    p2[l]++;
    p2[r + 1] += -(r - l + 2);
    p2[r + 2] += r - l + 1;
}

void f2(int l, int r, int num, vector<int>& p1, vector<int>& p2) {
    if (r < l) return;
    p1[l] += num;
    p1[r + 1] -= num;
}

void f3(int l, int r, vector<int>& p0, vector<int>& p1, vector<int>& p2) {
    if (r < l) return;
    p1[l] += (r - l + 2);
    p1[r + 1] -= (r - l + 2);

    p2[l]--;
    p2[r + 1] += r - l + 2;
    p2[r + 2] += -(r - l + 1);
}

int fixed_a() {
    vector<int> p0(2 * max_n), p1(2 * max_n), p2(2 * max_n);

    /*cout << "a: " << endl;
    for(int i = 0;i < n;i++)
        cout << a[i] << " ";
    cout << endl;*/

    for(int i = 0;i < n;i++) {
        //if (a[i] == per[i].se - per[i].fi + 1) continue;

        int len = min(k, per[i].se - per[i].fi + 1);

        int l1 = per[i].fi + a[i];
        int r1 = l1 + len - a[i] - 1;

        int r3 = per[i].se + k - a[i] - 1;
        int l3 = r3 - (len - a[i] - 1);

        if (l3 <= r1) {
            l3 = (l3 + r1) / 2;
            r1 = l3 - 1;
        }

        if (r3 < l1) continue;

        int l2 = r1 + 1;
        int r2 = l3 - 1;

        //cout << l1 << " " << r1 << " " << l3 << " " << r3 << endl;


        f1(l1, r1, p0, p1, p2);
        f2(l2, r2, len - a[i], p1, p2);
        f3(l3, r3, p0, p1, p2);
    }

    for(int i = 1;i < 2 * max_n;i++)
        p2[i] += p2[i - 1];
    for(int i = 1;i < 2 * max_n;i++) {
        p2[i] += p2[i - 1];
        p1[i] += p1[i - 1];
    }

    int mx = 0;
    for(int i = 0;i < 2 * max_n;i++)
        mx = max(mx, p1[i] + p2[i]);

    //cout << "mx " << mx << endl;

    return mx;
}

void solve() {
    int te;
    cin >> te >> n >> k;
    for(int i = 0;i < n;i++)
        cin >> per[i].fi >> per[i].se;

    int res = 0;
    for(int l = 0;l <= te;l++) {
        int new_res = 0;
        for(int j = 0;j < n;j++) {
            a[j] = max(0ll, min(per[j].se, l + k - 1) - max(per[j].fi, l) + 1);

            new_res += a[j];
        }

        new_res += fixed_a();

        res = max(res, new_res);
        //cout << l << " " << res << endl;
    }

    cout << res << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}