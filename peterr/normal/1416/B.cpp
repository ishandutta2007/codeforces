#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E4;
int a[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % n != 0)
        {
            cout << "-1\n";
            continue;
        }
        int target = sum / n;
        vector<tuple<int, int, int>> ans;
        int ind = -1;
        for (int i = n; i >= 1; i--)
        {
            if (a[i] < i)
                continue;
            ind = i;
            int num = a[i] / i;
            ans.push_back({i, 1, num});
            a[i] -= num * i;
            a[1] += num * i;
            break;
        }
        if (ind == -1)
        {
            cout << "-1\n";
            continue;
        }
        for (int j = ind; j >= 2; j--)
        {
            int rem = j - a[j] % j;
            ans.push_back({1, j, rem});
            a[1] -= rem;
            a[j] += rem;
            int num = a[j] / j;
            ans.push_back({j, 1, num});
            a[1] += num * j;
            a[j] = 0;
        }
        bool over = false;
        for (int i = ind + 1; i <= n; i++)
        {
            if (a[i] > target)
                over = true;
        }
        if (over)
        {
            vector<pair<int, int>> vec;
            for (int i = ind + 1; i <= n; i++)
            {
                vec.push_back({(i - a[i] % i) % i, i});
            }
            sort(vec.begin(), vec.end());
            for (pair<int, int> pr : vec)
            {
                if (a[1] < pr.first)
                    break;
                ans.push_back({1, pr.second, pr.first});
                a[1] -= pr.first;
                a[pr.second] += pr.first;
                int num = a[pr.second] / pr.second;
                ans.push_back({pr.second, 1, num});
                a[1] += num * pr.second;
                a[pr.second] = 0;
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (a[i] >= target || target - a[i] > a[1])
                continue;
            ans.push_back({1, i, target - a[i]});
            a[1] -= target - a[i];
            a[i] = target;
        }
        bool valid = true;
        for (int i = 1; i < n; i++)
            valid = valid && a[i] == a[i + 1];
        if (valid)
        {
            cout << ans.size() << "\n";
            for (tuple<int, int, int> tup : ans)
                cout << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << "\n";
        }
        else
            cout << "-1\n";
    }
    return 0;
}