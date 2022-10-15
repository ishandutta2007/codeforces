// ./e-change-free.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 10, MC = 100;
int N,
    baseBills[MN];
ll M,
   C[MN], W[MN], ccost[MN];
bool pay[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (auto i = 1; i <= N; i++) {
        cin >> C[i];
        baseBills[i] = C[i]/100;
        C[i] %= 100;
    }
    for (auto i = 1; i <= N; i++) cin >> W[i];

    ll cost = 0;
    for (auto i = 1; i <= N; i++) {
        if (C[i]) {
            ccost[i] = (100 - C[i]) * W[i];
            cost += ccost[i];
        }
        else pay[i] = true;
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (auto i = 1; i <= N; i++) {
        if (C[i]) {
            M += 100 - C[i];
            if (M >= 100) {
                pq.emplace(ccost[i], i);
                M -= 100;
                cost -= ccost[i];
                pay[i] = true;
            }
            else if (!pq.empty()) {
                auto [tcost, tidx] = pq.top();
                if (tcost < ccost[i]) {
                    pq.pop();
                    cost -= ccost[i] - tcost;
                    pay[tidx] = false;
                    pay[i] = true;
                    pq.emplace(ccost[i], i);
                }
            }
        }
    }

    cout << cost << '\n';
    for (auto i = 1; i <= N; i++) {
        if (pay[i])
            cout << baseBills[i] << ' ' << C[i] << '\n';
        else
            cout << baseBills[i]+1 << " 0\n";
    }

    return 0;
}