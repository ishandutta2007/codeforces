#include <iostream>
#include <algorithm>

using namespace std;

bool check(pair<int, int>* pairs, int n, int m, int x)
{
    int count = 0;
    int* freq = new int[n + 1];
    fill(freq, freq + n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a = pairs[i].first;
        int b = pairs[i].second;
        if (a != x && b != x)
        {
            count++;
            freq[a]++;
            freq[b]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == count)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    pair<int, int>* pairs = new pair<int, int>[m];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        pairs[i] = {a, b};
    }

    if (check(pairs, n, m, pairs[0].first))
    {
        cout << "YES";
    }
    else if (check(pairs, n, m, pairs[0].second))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}