#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 1e5 + 5;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = s.length();

    string distinct;
    vector<int> st;
    vector<pair<int, string>> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        if (distinct.size() == 1 and st.back() == i + 1 and s[i + 1] == s[i]) {
            st.pop_back();
            if (st.empty()) {
                distinct.pop_back();
            }
        } else if (distinct.length() > 1 and st.back() == i + 1 and s[i + 1] == s[i] and distinct[distinct.length() - 2] < s[i]) {
            st.pop_back();
            if (s[st.back()] != s[i]) {
                distinct.pop_back();
            }
        } else {
            st.push_back(i);
            if (distinct.empty() or distinct.back() != s[i]) {
                distinct += s[i];
            }
        }

        ans[i].first = st.size();
        if (st.size() > 10) {
            for (int j = st.size() - 1; j >= st.size() - 5; j--) {
                ans[i].second += s[st[j]];
            }
            ans[i].second += "...";
            ans[i].second += s[st[1]];
            ans[i].second += s[st[0]];
        } else {
            for (int j = st.size() - 1; j >= 0; j--) {
                ans[i].second += s[st[j]];
            }
        }
    }

    for (auto& [len, str] : ans) {
        cout << len << ' ' << str << '\n';
    }
    return 0;
}