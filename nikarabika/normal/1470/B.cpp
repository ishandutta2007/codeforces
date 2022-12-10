//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1000 * 1001;
vector<int> ps[maxn];
int groups[maxn];
int grp[maxn],
    cnt[maxn];
bool isp[maxn];

int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(isp, true, sizeof isp);
    iota(grp, grp + maxn, 0);
    for (int i = 2; i < maxn; i++)
        if (isp[i])
            for (int j = i + i; j < maxn; j += i) {
                bool cnt = 0;
                while (grp[j] % i == 0)
                    grp[j] /= i, cnt ^= 1;
                if (cnt)
                    grp[j] *= i;
                isp[j] = false;
            }
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

int solve() {
    int n;
    cin >> n;
    int gsz = n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[grp[a[i]]] = 0;
        groups[i] = grp[a[i]];
    }
    sort(groups, groups + gsz);
    gsz = unique(groups, groups + gsz) - groups;
    int maxinit = 0;
    for (int i = 0; i < n; i++) {
        cnt[grp[a[i]]]++;
        smax(maxinit, cnt[grp[a[i]]]);
    }
    int evens = 0;
    int maxodd = -1;
    for (int i = 0; i < gsz; i++) {
        int g = groups[i];
        if (g != 1) {
            if (cnt[g] & 1)
                smax(maxodd, cnt[g]);
            else
                evens += cnt[g];
        }
        else
            evens += cnt[g];
    }
    int nextans = max(evens, maxodd);
    int q;
    cin >> q;
    while (q--) {
        LL w;
        cin >> w;
        if (w == 0)
            cout << maxinit << '\n';
        else
            cout << nextans << '\n';
    }
    return 0;
}