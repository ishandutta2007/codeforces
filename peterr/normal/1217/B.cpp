#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int d[MAXN];
int h[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int thresh = 0, delta = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> d[i] >> h[i];
            thresh = max(thresh, d[i]);
            delta = min(delta, h[i] - d[i]);
        }
        if (delta >= 0)
        {
            if (x <= thresh)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            if (x <= thresh)
            {
                cout << 1 << endl;
            }
            else
            {
                x -= thresh;
                cout << (x + abs(delta) - 1) / (abs(delta)) + 1 << endl;
            }

        }
    }
    return 0;
}