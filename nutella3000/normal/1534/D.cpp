#include <bits/stdc++.h>
using namespace std;

template<class T1, class T2>
void sMin(T1 &a, T2 b) {
    a = min(a, (T1) b);
}
template<class T1, class T2>
void sMax(T1 &a, T2 b) {
    a = max(a, (T1) b);
}

#define int long long
typedef long long ll;
#define size(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair

template<class IT>
void print(IT b, IT e, string sep=" ", string en="\n") {
    while (b != e) {
        cout << *(b++) << sep;
    }
    cout << en;
}

void run();

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(15);
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}

const int inf = 1e9 + 7;
const int max_n = 2001;

int n;
bool used[max_n];

vector<pii> ed;
vector<int> di;

void leaf(int v) {
    used[v] = true;
    cout << "? " << v + 1 << endl;
    vector<int> d(n);
    int pr = -1;
    vector<int> ch;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        if (d[i] == 1 && !used[i]) pr = i;
        if (d[i] == 2 && !used[i]) ch.emplace_back(i);
    }
    ed.emplace_back(v, pr);
    used[pr] = true;
    for (int i : ch) {
        ed.emplace_back(pr, i);
        if (di[i] > di[pr]) used[i] = true;
    }
}

void run() {
    cin >> n;
    cout << "? 1" << endl;
    int v = 0;
    vector<pii> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i].fi;
        d[i].se = i;
        if (d[i].fi == 1) {
            ed.emplace_back(v, i);
        }
        di.emplace_back(d[i].fi);
    }
    used[v] = true;

    sort(all(d));
    for (int i = n - 1; i >= 0; --i) {
        if (used[d[i].se]) continue;
        if (d[i].fi == 1) continue;
        leaf(d[i].se);
    }
    cout << "!" << endl;
    for (pii i : ed)
        cout << i.fi + 1 << " " << i.se + 1 << endl;
}