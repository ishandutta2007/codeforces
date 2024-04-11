// ./b-3-coloring.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    vector<pair<int, int>> need[2];
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < N; j++) {
            if (i == 0 && j == 0) continue;
            need[(i+j)%2].push_back({i+1, j+1});
        }
    }
    // for (auto [x, y] : need[0])
    //     printf("0 %d %d\n", x, y);
    // for (auto [x, y] : need[1])
    //     printf("1 %d %d\n", x, y);
    // fflush(stdout);

    int c1 = -1, c2 = -1;
    for (auto i = 0; i < N*N; i++) {
        int c; cin >> c;

        if (i == 0) {
            if (c == 1) { cout << "2 1 1\n"; c1 = 2; }
            else { cout << "1 1 1\n"; c1 = 1; }
            c2 = c1 == 1 ? 2 : 1;
        }
        else {
            assert(c1 != -1);
            int doany = -1;
            if (c == c1) { // want to attach to 1
                if (!need[1].empty()) {
                    auto [x, y] = need[1].back(); need[1].pop_back();
                    cout << c2 << ' ' << x << ' ' << y << '\n';
                }
                else doany = 0;
            }
            else {
                if (!need[0].empty()) {
                    auto [x, y] = need[0].back(); need[0].pop_back();
                    cout << c1 << ' ' << x << ' ' << y << '\n';
                }
                else doany = 1;
            }

            // if (doany != -1)
            // printf("doany=%d\n",doany);
            // fflush(stdout);

            // assert(!(need[0].empty() && need[1].empty()));
            if (doany != -1) {
                assert(!need[doany].empty());
                auto [x, y] = need[doany].back(); need[doany].pop_back();
                int use = -1, cannot = doany == 0 ? c2 : c1;
                for (auto i = 1; i <= 3; i++)
                    if (i != cannot && i != c)
                        use = i;
                cout << use << ' ' << x << ' ' << y << '\n';
            }
        }

        cout.flush();
    }

    return 0;
}