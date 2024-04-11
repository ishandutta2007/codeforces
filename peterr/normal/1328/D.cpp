#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int t[MAXN];
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        bool same = false;
        bool allSame = true;
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> t[i];
            if (i && t[i] == t[i - 1])
            {
                same = true;
                ind = i;
            }
            if (t[i] != t[0])
                allSame = false;
        }
        if (t[n - 1] == t[0])
        {
            same = true;
            ind = 0;
        }
        if (allSame)
        {
            cout << "1\n";
            for (int i = 0; i < n; i++)
                cout << 1 << " \n"[i == n - 1];
        }
        else if (n % 2 == 0)
        {
            cout << 2 << "\n";
            for (int i = 0; i < n; i++)
            {
                cout << (i & 1) + 1 << " \n"[i == n - 1];
            }
        }
        else
        {
            if (!same)
            {
                cout << 3 << "\n";
                for (int i = 0; i < n - 1; i++)
                    cout << (i & 1) + 1 << " ";
                cout << "3\n";
            }
            else
            {
                cout << 2 << "\n";
                for (int i = 0; i < n - 1; i++)
                {
                    ans[(ind + i) % n] = (i & 1) + 1;
                }
                ans[(ind - 1 + n) % n] = 1;
                for (int i = 0; i < n; i++)
                    cout << ans[i] << " \n"[i == n - 1];
            }
        }
    }
    return 0;
}