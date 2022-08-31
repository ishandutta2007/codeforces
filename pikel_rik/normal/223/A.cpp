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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    n = s.length();

    stack<int> st;
    vector<pair<int, int>> a;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(' or s[i] == '[')
            st.push(i);
        else if (s[i] == ')' and !st.empty() and s[st.top()] == '(') {
            while (!a.empty() and a.back().first > st.top() and a.back().second < i)
                a.pop_back();
            if (!a.empty() and a.back().second == st.top() - 1)
                st.top() = a.back().first, a.pop_back();
            a.emplace_back(st.top(), i), st.pop();
        }
        else if (s[i] == ']' and !st.empty() and s[st.top()] == '[') {
            while (!a.empty() and a.back().first > st.top() and a.back().second < i)
                a.pop_back();
            if (!a.empty() and a.back().second == st.top() - 1)
                st.top() = a.back().first, a.pop_back();
            a.emplace_back(st.top(), i), st.pop();
        }
        else {
            while (!st.empty())
                st.pop();
        }
    }

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (s[i] == '[');
    }

    int best = -1, best_val = -1;

    for (int i = 0; i < a.size(); i++) {
        int num = pref[a[i].second + 1] - pref[a[i].first];
        if (num > best_val) {
            best_val = num;
            best = i;
        }
    }

    if (best == -1) {
        cout << "0\n";
        return 0;
    }

    cout << best_val << "\n";
    cout << s.substr(a[best].first, a[best].second - a[best].first + 1) << "\n";
    return 0;
}