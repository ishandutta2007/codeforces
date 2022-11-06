#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

void dfs(std::vector<std::vector<int> > adj, int u, int p)
{
    for (auto v : adj[u])
        if (v != p)
        {

        }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    m = 0;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i = 0;
    int mh = 0;
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += (v[i]);
    }
    int penh = 0;
    while (i < n) {
        int j = i;
        while (i < n - 1 && v[i] == v[i + 1]) {
            i++;
        }
        penh = max(0ll, penh + v[i] - mh - i + j - 1ll);
        cnt += (i - j + 1);
        mh = v[i++];
    }
    cnt += penh;
    cout << sum - cnt;// << "\n";
}