#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1E5;
long long special[MAXM];

int main()
{
    long long n, k;
    int m;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> special[i];
        special[i]--;
    }
    int numRemove = 0;
    int cur = 0;
    int ops = 0;
    while (numRemove < m)
    {
        int count = 1;
        long long page = (special[cur] - numRemove) / k;
        while (cur + 1 < m && (special[cur + 1] - numRemove) / k == page)
        {
            count++;
            cur++;
        }
        ops++;
        numRemove += count;
        cur++;
    }
    cout << ops;
    return 0;
}