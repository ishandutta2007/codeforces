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
        string b;
        cin >> n >> b;
        int prev = -1;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == '0')
            {
                if (prev == 1)
                    cout << 0, prev = 0;
                else
                    cout << 1, prev = 1;
            }
            else
            {
                if (prev == 2)
                    cout << 0, prev = 1;
                else
                    cout << 1, prev = 2;
            }
        }
        cout << "\n";
    }
    return 0;
}