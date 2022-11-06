#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        while ((int) v.size() > 1)
        {
            int x = v.back();
            v.pop_back();
            int y = v.back();
            v.pop_back();
            v.push_back((x + y + 1) / 2);
            ans.push_back(make_pair(x, y));
        }
        cout << "2\n";
        for (pair<int, int> pr : ans)
            cout << pr.first << " " << pr.second << "\n";
    }
    return 0;
}