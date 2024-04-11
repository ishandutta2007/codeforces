// ./e-two-houses.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

const int MN = 501;
int N;
pii deg[MN];

bool ask(int a, int b) {
    cout << "? " << a << ' ' << b << '\n'; cout.flush();
    string res; cin >> res;
    return res == "Yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 0; i < N; i++) {
        cin >> deg[i].first;
        deg[i].second = i;
    }
    sort(deg, deg+N);
    vector<tuple<int, int, int>> degp;
    for (auto i = 0; i < N; i++) {
        auto [da, a] = deg[i];
        for (auto j = i+1; j < N; j++) {
            auto [db, b] = deg[j];
            degp.emplace_back(db-da, a+1, b+1);
        }
    }
    sort(degp.begin(), degp.end(), greater<>());
    for (auto [_, a, b] : degp) {
        if (ask(b, a)) {
            cout << "! " << a << ' ' << b << '\n'; cout.flush();
            return 0;
        }
    }
    cout << "! 0 0\n"; cout.flush();

    return 0;
}