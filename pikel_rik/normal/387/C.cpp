#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int n;
string s;

bool comp(const string &x, const string &y) {
    if (x.length() != y.length())
        return x.length() < y.length();
    return x < y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    n = s.length();

    string temp;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        if (s[i] != '0' and !temp.empty()) {
            v.push_back(temp);
            temp.clear();
        }

        temp += s[i];
    }

    if (!temp.empty())
        v.push_back(temp);

    int c = 0;
    while (true) {
        string m = *max_element(all(v), comp);

        temp.clear();
        int ans = 0;

        for (int i = 0; i < v.size(); i++) {
            temp += v[i];
            if (!comp(temp, m)) {
                ans = i + 1;
                break;
            }
        }

        c += v.size() - ans;

        if (v.size() == ans)
            break;

        while (v.size() != ans) {
            v.pop_back();
        }
    }

    cout << 1 + c << "\n";
    return 0;
}