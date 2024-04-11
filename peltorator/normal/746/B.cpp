#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<char> ans;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    ans.resize(n);
    if (n % 2 == 1)
    {
        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                ans[n / 2 - i / 2] = s[i];
            else
                ans[n / 2 + i / 2 + 1] = s[i];
    }
    else
    {
        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                ans[n / 2 - i / 2 - 1] = s[i];
            else
                ans[n / 2 + i / 2] = s[i];
        reverse(ans.begin(), ans.end());
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    return 0;
}