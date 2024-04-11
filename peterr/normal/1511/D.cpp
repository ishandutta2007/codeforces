#include <bits/stdc++.h>

using namespace std;

void solve(int l, int r, vector<int> &v)
{
    if (l > r)
        return;
    int start = v.back();
    for (int i = l; i <= r; i++)
    {
        if (i == start)
            continue;
        v.push_back(start);
        v.push_back(i);
    }
    if (start == l)
        solve(l + 1, r, v);
    else
        solve(l, r - 1, v);
    v.push_back(start);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    ans.push_back(0);
    solve(0, k - 1, ans);
    string s = "";
    for (int x : ans)
        s = s + (char) (x + 'a');
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        cout << s[j];
        j++;
        if (j == (int) s.length())
            j = 1;
    }
    cout << "\n";
    return 0;
}