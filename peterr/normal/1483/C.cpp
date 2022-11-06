#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int h[MAXN];
int b[MAXN];
long long ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    multiset<long long> cand;
    vector<pair<int, long long>> st;
    for (int i = 0; i < n; i++)
    {
        long long cur = (i ? ans[i - 1] + b[i] : b[i]);
        while (!st.empty() && h[i] < h[st.back().first])
        {
            pair<int, long long> pr = st.back();
            st.pop_back();
            cand.erase(cand.find(pr.second));
            cur = max(cur, pr.second - b[pr.first] + b[i]);
        }
        st.push_back({i, cur});
        cand.insert(cur);
        ans[i] = *(--cand.end());
    }
    cout << ans[n - 1] << "\n";
    return 0;
}