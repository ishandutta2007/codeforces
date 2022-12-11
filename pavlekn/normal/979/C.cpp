#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y, v, u;
    cin >> n >> x >> y;
    vector<vector<int>> g = {};
    for (int i = 0; i < n; ++i)
    {
        g.push_back({});
    }
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> v >> u;
        g[v - 1].push_back(u - 1);
        g[u - 1].push_back(v - 1);
    }
    long long count1 = 0, count2 = 0;
    vector<int> s1 = {};
    for (int i = 0; i < n; ++i)
    {
        s1.push_back(-1);
    }
    vector<int> s2 = {};
    for (int i = 0; i < n; ++i)
    {
        s2.push_back(-1);
    }
    s1[y - 1] = 0;
    deque<int> st = {y - 1};
    while (!st.empty())
    {
        v = st.front();
        st.pop_front();
        for (auto w : g[v])
        {
            if (s1[w] == -1)
            {
                st.push_back(w);
                s1[w] = s1[v] + 1;
            }
        }
    }
    s2[x - 1] = 0;
    st = {x - 1};
    while (!st.empty())
    {
        v = st.front();
        st.pop_front();
        for (auto w : g[v])
        {
            if (s2[w] == -1)
            {
                st.push_back(w);
                s2[w] = s2[v] + 1;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (s2[i] - s1[i] == s1[x - 1])
        {
            ++count1;
        }
        if (s2[i] + s1[x - 1] == s1[i])
        {
            ++count2;
        }
    }
    long long n1 = (long long) n;
    cout << n1 * (n1 - 1) - count1 * count2 << endl;
}