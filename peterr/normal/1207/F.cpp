#include <bits/stdc++.h>

using namespace std;

const int N = 500000;
const int THRESHHOLD = 700;
int table[THRESHHOLD][THRESHHOLD];
int arr[N + 1];

int main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
        {
            arr[x] += y;
            for (int j = 1; j < THRESHHOLD; j++)
            {
                table[j][x % j] += y;
            }
        }
        else
        {
            int ans = 0;
            if (x >= THRESHHOLD)
            {
                for (int i = y; i <= N; i += x)
                {
                    ans += arr[i];
                }
            }
            else
            {
                ans = table[x][y];
            }
            cout << ans << endl;
        }
    }
    return 0;
}