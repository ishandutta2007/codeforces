#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> s;

    string best = s;
    for (int i = 0; i < 11; i++) {
        string temp = s;
        for (int j = 0; j < n - 1; j++) {
            char ch = temp.back();
            temp.pop_back();

            temp = ch + temp;
            s = min(s, temp);
        }
        best = min(best, s);
        for (int j = 0; j < n; j++) {
            if (s[j] < '9')
                s[j] += 1;
            else s[j] = '0';
        }
    }

    cout << best << "\n";
    return 0;
}