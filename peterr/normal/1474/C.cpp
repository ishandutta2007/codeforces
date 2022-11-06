#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
pair<int, int> a[2 * MAXN];
bool used[2 * MAXN];
map<int, int> s;
vector<pair<int, int>> ans;

bool solve(int n, int cur)
{
    while (!s.empty())
    {
        auto it = s.end();
        it--;
        if (!it->second)
        {
            s.erase(it);
            continue;
        }
        int val = it->first;
        int target = cur - val;
        if (!s.count(target) || !s[target])
            return false;
        s[val]--;
        s[target]--;
        ans.push_back({val, target});
        cur = val;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        s.clear();
        ans.clear();
        int n;
        cin >> n;

        for (int i = 0; i < 2 * n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
            //cout << "a " << i << " " << a[i] << endl;
        }
        if (n == 1)
        {
            cout << "YES\n";
            cout << a[0].first + a[1].first << "\n";
            cout << a[0].first << " " << a[1].first << "\n";
            continue;
        }
        sort(a, a + 2 * n);
        bool valid = false;
        int sum = -1;
        for (int i = 2 * n - 2; i >= 0; i--)
        {
            s.clear();
            for (int j = 0; j < 2 * n; j++)
            {
                s[a[j].first]++;
            }
            ans.clear();
            ans.push_back({a[2 * n - 1].first, a[i].first});
            sum = a[2 * n - 1].first + a[i].first;
            s[a[2 * n - 1].first]--;
            s[a[i].first]--;
            if (solve(n, a[2 * n - 1].first))
            {
                valid = true;
                break;
            }
        }
        if (!valid)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << sum << "\n";
        for (pair<int, int> pr : ans)
        {
            cout << pr.first << " " << pr.second << "\n";
        }
    }
    return 0;
}