#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int pos = 0;
        while (s[pos] != '*')
            pos++;
        int ans = 0;
        while (pos < n)
        {
            ans++;
            int newpos = min(n - 1, pos + k);
            while (newpos > pos && s[newpos] != '*')
                newpos--;
            if (newpos == pos)
                break;
            pos = newpos;
        }
        cout << ans << "\n";
    }
    return 0;
}