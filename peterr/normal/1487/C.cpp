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
        cin >> n;
        if (n & 1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (j <= i + n / 2)
                        cout << "1 ";
                    else
                        cout << "-1 ";
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (j == i + n / 2)
                        cout << "0 ";
                    else if (j < i + n / 2)
                        cout << "1 ";
                    else
                        cout << "-1 ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}