#include <iostream>

using namespace std;

bool check(int* arr, int n, int m, int ops)
{
    int prev = arr[0];
    if (ops >= m - prev)
        prev = 0;
    for (int i = 1; i < n; i++)
    {
        int cur = arr[i];
        if (cur < prev)
        {
            if (ops < prev - cur)
                return false;
        }
        else if (cur > prev)
        {
            if (ops < (m - cur) + prev)
                prev = cur;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (check(arr, n, m, 0))
    {
        cout << 0;
    }
    else
    {
        int ops = 0;
        for (int jump = m / 2; jump > 0; jump /= 2)
        {
            while (!check(arr, n, m, ops + jump))
                ops += jump;
        }

        cout << (ops + 1);
    }

    return 0;
}