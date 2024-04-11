#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define sz(x) ((int)(x).size())
#define smax(x, y) (x) = max((x), (y))
#define smin(x, y) (x) = min((x), (y))
#define L first
#define R second
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

const int maxn = 100 * 1000 + 10;
bool isp[maxn],
     mark[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(isp, true, sizeof isp);
    isp[0] = isp[1] = false;
    for (int i = 0; i < maxn; i++)
        if (isp[i])
            for (int j = i + i; j < maxn; j += i)
                isp[j] = false;
    int n;
    cin >> n;
    for (int i = n; i + i > n; i--)
        if (isp[i])
            mark[i] = true;
    mark[1] = true;
    vector<pii> ans;
    for (int i = 3; i <= n; i++) if (isp[i] and !mark[i]) {
        vector<int> vec;
        for (int j = i; j <= n; j += i)
            if (!mark[j])
                vec.PB(j);
        if (sz(vec) & 1)
            vec.erase(vec.begin() + 1);
        for (int i = 0; i < sz(vec); i += 2) {
            ans.PB(pii(vec[i], vec[i + 1]));
            mark[vec[i]] = mark[vec[i + 1]] = true;
        }
    }
    int prv = -1;
    for (int i = 1; i <= n; i++)
        if (!mark[i])
            if (prv == -1)
                prv = i;
            else {
                ans.PB(pii(prv, i));
                prv = -1;
            }
    cout << ans.size() << '\n';
    for (int i = 0; i < sz(ans); i++)
        cout << ans[i].L << ' ' << ans[i].R << '\n';
    return 0;
}