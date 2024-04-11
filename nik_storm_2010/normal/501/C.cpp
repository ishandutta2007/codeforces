#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef pair <int, int> pii;
const int N = 1e5;

set <pii> base;
int degree[N], sum[N];
vector <pii> print;

int main() {
    ios_base::sync_with_stdio(false);
    int n{};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> degree[i] >> sum[i];
    for (int i = 0; i < n; i++)
        base.insert({degree[i], i});
    while (!base.empty()) {
        pii cur{};
        cur = *base.begin();
        base.erase(base.begin());
        if (cur.first == 0)
            continue;
        int x{}, y{};
        x = cur.second;
        y = sum[x];
        print.push_back({x, y});
        base.erase(base.find({degree[y], y}));
        degree[y]--;
        sum[y] ^= x;
        base.insert({degree[y], y});
    }
    cout << print.size() << "\n";
    for (size_t i = 0; i < print.size(); i++)
        cout << print[i].first << " " << print[i].second << "\n";
    return 0;
}