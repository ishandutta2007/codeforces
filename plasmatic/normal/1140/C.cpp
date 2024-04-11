// ./c-playlist.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

const int MN = 3e5 + 1;
int N, K;
pair<int, ll> ss[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (auto i = 0; i < N; i++) {
        int t, b; cin >> t >> b;
        ss[i] = {b, t};
    }
    sort(ss, ss+N);
    ll ans = 0, cur = 0;
    priority_queue<int> rem;
    for (auto i = N-1; i >= 0; i--) {
        auto p = ss[i];

        rem.push(-p.second); cur += p.second;
        if ((int)rem.size() > K) {
            cur -= -rem.top();
            rem.pop();
        }

        ans = max(ans, cur * p.first);
    }
    cout << ans << '\n';

    return 0;
}