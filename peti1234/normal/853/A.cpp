#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vb = vector<bool>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vii = vector<ii>;
#define INF 1000000000
#define PI 3.14159265358979323846
#define fi first
#define se second
#define pb push_back
#define sz(cont) static_cast<int>((cont).size())
#define all(cont) (cont).begin(),(cont).end()
#define REP(n) for(int i=1, _i=(n); i<=_i; ++i)
#define FOR(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define DWN(i,n) for(int i=(n); i>=0; --i)
#define FORI(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
int n, k;
priority_queue<ii> m;
int t[10000001];
int l[10000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    k++;
    REP(n) {
        cin >> t[i];
    }
    REP(min(2 * n, n + k-1)) {
        if (i <= k && i <= n) {
            m.push({ t[i], i });
        }
        if (i == k || i >= n) {
            if (m.empty()) {
                break;
            }
            l[m.top().se] = k;
            m.pop();
            k++;
        }
    }
    long long p = 0;
    for (int i = 1; i <= n; i++) {
        p += (long long)(l[i] - i)*t[i];
    }
    cout << p << endl;
    REP(n) {
        cout << l[i] << " ";
    }
}