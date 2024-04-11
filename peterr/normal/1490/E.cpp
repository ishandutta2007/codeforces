#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
pair<int, int> a[MAXN];

bool check(int ind, int n)
{
    long long sum = a[ind].first;
    for (int i = 0; i < n; i++)
    {
        if (i == ind)
            continue;
        if (a[i].first > sum)
            return false;
        sum += a[i].first;
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        sort(a, a + n);
        int ind = -1;
        //check(1, n);
        for (int jump = n; jump; jump >>= 1)
        {
            while (ind + jump < n && !check(ind + jump, n))
            {
                ind += jump;
            }
        }
        vector<int> ans;
        for (int i = ind + 1; i < n; i++)
        {
            ans.push_back(a[i].second);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}