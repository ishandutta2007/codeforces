#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int x[MAXN];
bool visited[MAXN + 7];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x, x + n);
    int maxAns = 0;
    int minAns = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[x[i] - 1])
        {
            visited[x[i] - 1] = true;
            maxAns++;
        }
        else if (!visited[x[i]])
        {
            visited[x[i]] = true;
            maxAns++;
        }
        else if (!visited[x[i] + 1])
        {
            visited[x[i] + 1] = true;
            maxAns++;
        }
    }
    int ptr = 0;
    while (ptr < n)
    {
        int cur = x[ptr];
        while (ptr < n && x[ptr] == cur)
        {
            ptr++;
        }
        if (ptr < n && x[ptr] == cur + 1)
        {
            minAns++;
            while (ptr < n && x[ptr] == cur + 1)
            {
                ptr++;
            }
            if (ptr < n && x[ptr] == cur + 2)
            {
                while (ptr < n && x[ptr] == cur + 2)
                {
                    ptr++;
                }
            }
        }
        else if (ptr < n && x[ptr] == cur + 2)
        {
            minAns++;
            while (ptr < n && x[ptr] == cur + 2)
            {
                ptr++;
            }
        }
        else
        {
            minAns++;
        }
    }
    cout << minAns << " " << maxAns << endl;
    return 0;
}