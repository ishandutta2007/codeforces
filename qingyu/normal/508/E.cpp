#include <bits/stdc++.h>

const int N = 1e5 + 50;
int n, l[N], r[N];
std::stack<std::pair<int, int>> st;
std::vector<char> ans;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    auto report = [&]()
    {
        puts("IMPOSSIBLE");
        exit(0);
    };
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> l[i] >> r[i];
        ans.push_back('(');
        st.emplace(ans.size() + l[i], ans.size() + r[i]);
        while (!st.empty())
        {
            auto [l, r] = st.top();
            if (ans.size() + 1 > r) report();
            if (ans.size() + 1 < l) break;
            ans.push_back(')');
            st.pop();
        }
    }
    if (!st.empty()) report();
    for (auto c : ans) putchar(c);
}