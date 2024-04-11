#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int crit = 0;
    for (int i = 1; i < b.length(); i++)
    {
        if (b[i] != b[i - 1])
            crit++;
    }
    crit %= 2;
    bool parity = 0;
    for (int i = 0; i < b.length(); i++)
    {
        if (a[i] != b[i])
            parity = !parity;
    }
    int ans = (parity == 0);
    for (int i = b.length(); i < a.length(); i++)
    {
        if (crit)
            parity = !parity;
        if (a[i] != b[b.length() - 1])
            parity = !parity;
        if (a[i - b.length()] != b[0])
            parity = !parity;
        if (parity == 0)
            ans++;
    }
    cout << ans;
    return 0;
}