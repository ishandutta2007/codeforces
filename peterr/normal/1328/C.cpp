#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E4;
int a[MAXN];
int b[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        bool bigger = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                a[i] = b[i] = 0;
            }
            else if (s[i] == '1')
            {
                a[i] = 1;
                b[i] = 0;
                if (bigger)
                {
                    swap(a[i], b[i]);
                }
                bigger = true;
            }
            else if (s[i] == '2')
            {
                if (bigger)
                {
                    a[i] = 0;
                    b[i] = 2;
                }
                else
                {
                    a[i] = b[i] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << "\n";
        for (int i = 0; i < n; i++)
            cout << b[i];
        cout << "\n";
    }
    return 0;
}