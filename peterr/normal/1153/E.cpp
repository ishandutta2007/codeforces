#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
bool rowOdd[MAXN + 1];
bool colOdd[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        printf("? %d %d %d %d\n", 1, 1, i, n);
        fflush(stdout);
        int num;
        cin >> num;
        colOdd[i] = num % 2;
        printf("? %d %d %d %d\n", 1, 1, n, i);
        fflush(stdout);
        cin >> num;
        rowOdd[i] = num % 2;
    }
    int x1 = n + 1, y1 = n + 1, x2 = n + 1, y2 = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (colOdd[i])
        {
            x1 = min(x1, i);
        }
        else if (x1 < n + 1)
        {
            x2 = min(x2, i);
        }
        if (rowOdd[i])
        {
            y1 = min(y1, i);
        }
        else if (y1 < n + 1)
        {
            y2 = min(y2, i);
        }
    }
    if (x1 < n + 1 && y1 < n + 1)
    {
        printf("? %d %d %d %d\n", x1, y1, x1, y1);
        fflush(stdout);
        int num;
        cin >> num;
        if (num != 1)
            swap(y1, y2);
        printf("! %d %d %d %d\n", x1, y1, x2, y2);
    }
    else
    {
        bool flip = false;
        if (y1 == n + 1)
        {
            flip = true;
            swap(x1, y1);
            swap(x2, y2);
        }
        int left = 1, right = n;
        while (left < right)
        {
            int mid = (left + right) / 2;

            if (flip)
                printf("? %d %d %d %d\n", y1, left, y1, mid);
            else
                printf("? %d %d %d %d\n", left, y1, mid, y1);
            fflush(stdout);
            int num;
            cin >> num;
            if (num % 2 == 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        x1 = x2 = left;
        if (flip)
        {
            swap(x1, y1);
            swap(x2, y2);
        }
        printf("! %d %d %d %d\n", x1, y1, x2, y2);
    }
    return 0;
}