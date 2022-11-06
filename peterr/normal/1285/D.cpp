#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> a;

int solve(int digit, vector<int> &v)
{
    if (digit == -1)
    {
        int ans = v[0];
        for (int x : v)
            ans = max(ans, x);
        return ans;
    }
    bool same = true;
    for (int i = 1; i < (int) v.size(); i++)
    {
        if ((v[0] & (1 << digit)) != (v[i] & (1 << digit)))
            same = false;
    }
    vector<int> temp;
    if (same)
    {
        for (int x : v)
            temp.push_back(x & ~(1 << digit));
        return solve(digit - 1, temp);
    }
    else
    {
        for (int x : v)
            if (x & (1 << digit))
                temp.push_back(x);
        int ans = solve(digit - 1, temp);
        temp.clear();
        for (int x : v)
            if ((x & (1 << digit)) == 0)
                temp.push_back(x | (1 << digit));
        ans = min(ans, solve(digit - 1, temp));
        return ans;
    }

}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << solve(30, a) << endl;
    return 0;
}