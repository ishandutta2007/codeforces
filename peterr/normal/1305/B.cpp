#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    bool good = true;
    int n = (int) s.length();
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '(' && s[i + 1] == ')')
            good = false;
    }
    if (good)
    {
        cout << 0 << endl;
        return 0;
    }
    int p1, p2;
    p1 = 0;
    p2 = n - 1;
    vector<int> ans;
    while (p1 < p2)
    {
        while (p1 < p2 && s[p1] == ')')
            p1++;
        while (p2 > p1 && s[p2] == '(')
            p2--;
        if (p1 < p2)
        {
            ans.push_back(p1 + 1);
            ans.push_back(p2 + 1);
            p1++;
            p2--;
        }
    }
    cout << 1 << endl;
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}