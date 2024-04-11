#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        fill(a, a + n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < d; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (a[j])
                {
                    a[j]--;
                    a[j - 1]++;
                    break;
                }
            }
        }
        cout << a[0] << endl;
    }
    return 0;
}