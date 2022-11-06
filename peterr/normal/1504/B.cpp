#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string a, b;
        cin >> n >> a >> b;
        a += "0";
        b += "0";
        int bal = 0;
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '0')
                bal++;
            else
                bal--;
            if ((a[i] == b[i]) ^ (a[i + 1] == b[i + 1]) && bal)
                ans = false;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}