#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        bool valid = true;
        for (int i = 0; i < (int) a.length(); i++)
        {
            if (c[i] != b[i] && c[i] != a[i])
                valid = false;
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}