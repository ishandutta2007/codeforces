#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int cnt = 0;
        bool ans = u <= v;
        for (int i = 0; i < 30; i++)
        {
            if (u & (1 << i))
                cnt++;
            if (v & (1 << i))
                cnt--;
            if (cnt < 0)
                ans = false;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}