#include <iostream>

using namespace std;

const int INFINITY = 2e9+3;

int solve(int* b, int m, int k, int cancelFirst, int tb, int* next)
{
    if (cancelFirst < 0 || cancelFirst > k)
        return -1;
    int index = next[cancelFirst];
    if (index == -1)
        return INFINITY;
    index += (k - cancelFirst);
    if (index >= m)
        return INFINITY;
    return b[index] + tb;
}

int main()
{
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    int* a = new int[n];
    int* b = new int[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    if (k >= n || k >= m)
    {
        cout << -1;
    }
    else
    {
        int* next = new int[n];
        int start = 0, end = 0;
        while (start < n)
        {
            while (end < m && a[start] + ta > b[end])
                end++;
            if (end < m)
                next[start] = end;
            else
                next[start] = -1;
            start++;
        }


        int maxTime = 0;
        int aCancel = 0;
        while (aCancel <= k)
        {
            int time = solve(b, m, k, aCancel, tb, next);
            if (time > maxTime)
                maxTime = time;
            aCancel++;
        }

        if (maxTime == INFINITY)
            cout << -1;
        else
            cout << maxTime;
    }

    return 0;
}