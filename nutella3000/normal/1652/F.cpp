#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair
#define siz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb emplace_back
#define pii pair<int, int>
#define chmax(a, b) a = max(a, b)

const int N = (1 << 18);

int n;
string s;
int so[N], iso[N], cl[N], cnt[N], nso[N], ncl[N];

void run() { // tvari
    cin >> n >> s; n = (1 << n);

    iota(so, so + n, 0);
    sort(so, so + n, [](int v1, int v2) { return s[v1] < s[v2]; });
    
    for (int i = 0; i < n; ++i)
        iso[so[i]] = i;
    for (int i = 1; i < n; ++i)
        cl[i] = cl[i-1] + (s[so[i]] != s[so[i-1]]);

    for (int k = 1; k < n; k *= 2) {
        /*for (int i = 0; i < n; ++i)
            cout << so[i] << " ";
        cout << endl;
        for (int i = 0; i < n; ++i)
            cout << cl[i] << " ";
        cout << endl << endl;*/

        // i -> (i, iso[so[i] ^ k])
        fill(cnt, cnt+n, 0);
        for (int i = 0; i < n; ++i)
            ++cnt[cl[i]];
        for (int i = 1; i < n; ++i)
            cnt[i] += cnt[i-1];

        for (int i = n-1; i >= 0; --i) {
            // (so[i] ^ k, so[i])
            nso[--cnt[cl[iso[so[i] ^ k]]]] = so[i] ^ k;
        }
        for (int i = 1; i < n; ++i) {
            // nso[i], nso[i]^k 
            ncl[i] = ncl[i-1];
            int v = nso[i], p = nso[i-1];
            if (cl[iso[v]] != cl[iso[p]] || cl[iso[v^k]] != cl[iso[p^k]]) {
                ++ncl[i];
            }
        }

        for (int i = 0; i < n; ++i) {
            so[i] = nso[i];
            iso[so[i]] = i;
            cl[i] = ncl[i];
        }
    }
    //cout << so[0] << endl;
    for (int i = 0; i < n; ++i)
        cout << s[i^so[0]];
    cout << endl;
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}