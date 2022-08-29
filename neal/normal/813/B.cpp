#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int64_t X, Y, L, R;
    cin >> X >> Y >> L >> R;
    vector<int64_t> bad = {L - 1, R + 1};

    for (long double xa = 1; xa <= R; xa *= X)
        for (long double yb = 1; xa + yb <= R; yb *= Y)
            if (xa + yb >= L)
                bad.emplace_back(xa + yb);

    sort(bad.begin(), bad.end());
    bad.erase(unique(bad.begin(), bad.end()), bad.end());
    int64_t most = 0;

    for (int i = 0; i < int(bad.size()) - 1; i++)
        most = max(most, bad[i + 1] - bad[i] - 1);

    cout << most << '\n';
}