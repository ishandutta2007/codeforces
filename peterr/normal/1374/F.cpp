#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
pair<int, int> a[MAXN + 1];
int where[MAXN + 1];
vector<int> pos[MAXN + 1];
vector<int> ans;

bool solve(int n)
{
    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        v[i] = a[i];
    }
    int right = n;
    for (int i = MAXN; i >= 1; i--)
    {
        for (int j : pos[i])
        {
            if (right <= 3)
                break;
            for (int k = where[j]; k <= right - 2; k++)
            {
                ans.push_back(k);
                swap(v[k + 1], v[k + 2]);
                swap(v[k], v[k + 1]);
                where[v[k].second] = k;
                where[v[k + 1].second] = k + 1;
                where[v[k + 2].second] = k + 2;
            }
            if (where[j] < right)
            {
                ans.push_back(right - 2);
                swap(v[right - 1], v[right]);
                swap(v[right - 2], v[right - 1]);
                where[v[right].second] = right;
                where[v[right - 1].second] = right - 1;
                where[v[right - 2].second] = right - 2;
            }
            right--;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (v[1].first <= v[2].first && v[2].first <= v[3].first)
            break;
        ans.push_back(1);
        swap(v[2], v[3]);
        swap(v[1], v[2]);
        if (i == 3)
            return false;
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
        int n;
        cin >> n;
        ans.clear();
        for (int i = 1; i <= MAXN; i++)
        {
            pos[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
            pos[a[i].first].push_back(i);
            where[i] = i;
        }
        if (solve(n))
        {
            cout << (int) ans.size() << "\n";
            for (int x : ans)
                cout << x << " ";
            cout << "\n";
        }
        else
        {
            for (int i = 1; i <= n; i++)
                where[i] = i;
            ans.clear();
            bool valid = false;
            for (int i = 1; i <= MAXN; i++)
            {
                if ((int) pos[i].size() > 1)
                {
                    valid = true;
                    int temp1 = pos[i].back();
                    pos[i].pop_back();
                    int temp2 = pos[i].back();
                    pos[i].pop_back();
                    pos[i].push_back(temp1);
                    pos[i].push_back(temp2);
                    break;
                }
            }
            if (valid)
            {
                solve(n);
                cout << (int) ans.size() << "\n";
                for (int x : ans)
                    cout << x << " ";
                cout << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
    return 0;
}