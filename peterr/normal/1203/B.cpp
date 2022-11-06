#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int sides[4 * MAXN];

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < 4 * n; i++)
        {
            cin >> sides[i];
        }
        sort(sides, sides + 4 * n);
        bool valid = true;
        for (int i = 0; i < 4 * n; i += 2)
        {
            if (sides[i] != sides[i + 1])
                valid = false;
        }
        if (valid)
        {
            int left = 0, right = 4 * n - 1;
            int area = sides[left] * sides[right];
            while (left < right)
            {
                if (sides[right] * sides[left] != area)
                {
                    valid = false;
                }
                left += 2;
                right -= 2;
            }
        }
        if (valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}