#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 6;

vector<vector<int>> g(MAXN);

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, k;
    cin >> n >> k;
    if (n % 2 == 1 && k % 2 == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 1;
    while (ans * k < n || (ans * k - n) % 2 || (((ans * k - n) / 2 - 1 + n) / n) * 2 + 1 > ans)
    {
        ++ans;
    }
    int cnt = ans * k;
    vector<int> a(n, 1);
    cnt -= n;
    while (cnt > 0)
    {
        for (int i = 0; i < n; ++i)
        {
            if (cnt)
            {
                cnt -= 2;
                a[i] += 2;
            }
        }
    }
    int AA = 0;
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i)
    {
        s.insert({-a[i], i});
    }
    int A;
    for (int _ = 0; _ < ans; ++_)
    {
        cout << "? ";
        vector<int> used(n);
        vector<pair<int, int>> b;
        for (int i = 0; i < n; ++i)
        {
            b.push_back({-a[i], i});
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < k; ++i)
        {
            cout << b[i].second + 1 << " ";
            a[b[i].second]--;
        }
        cout << endl;
        cin >> A;
        AA ^= A;
    }
    cout << "! " << AA << endl;
    return 0;
}