#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> pi;
int N;
int L, R;
set<pi> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int a = 0; a < N; ++a) {
        cin >> L >> R;
        auto it = S.upper_bound(pi(R + 1, -1));

        if (it == S.begin()) S.emplace(L, R);
        else {
            --it;
            int st = L, en = R;
            while (it->second >= L) {
                st = min(st, it->first);
                en = max(en, it->second);
                if (it == S.begin()) {
                    S.erase(it); break;
                } else {
                    auto it2 = it; --it;
                    S.erase(it2);
                }
            }
            S.emplace(st, en);
        }

        cout << S.size() << "\n";
    }
    return 0;
}