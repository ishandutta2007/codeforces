#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int q[MAXN];
int first[MAXN + 1];
int last[MAXN + 1];
unordered_set<int> bob;

int main()
{
    int n, k;
    cin >> n >> k;
    fill(first, first + n + 1, k);
    fill(last, last + n + 1, -1);
    for (int i = 0; i < k; i++)
    {
        cin >> q[i];
        last[q[i]] = i;
        first[q[i]] = min(i, first[q[i]]);
        bob.insert(q[i]);
    }
    int rem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (first[i] < k)
        {
            if (i > 1)
            {
                if (last[i - 1] > first[i])
                    rem++;
            }
            if (i < n)
            {
                if (last[i + 1] > first[i])
                    rem++;
            }
        }
    }
    cout << 3 * n - 2 - rem - bob.size();

    return 0;
}