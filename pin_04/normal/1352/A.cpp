#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int base = 1;
        vector <int> ans;
        ans.clear();
        while (n)
        {
            if (n % 10) ans.push_back(base * (n % 10));
            base *= 10;
            n /= 10;
        }
        cout << ans.size() << "\n";
        for (int x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}