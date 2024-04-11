#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
pair<int, int> buses[MAXN];

int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> buses[i].first >> buses[i].second;
    }
    int bus = 0;
    int time = 1E6;
    for (int i = 0; i < n; i++)
    {
        if (buses[i].first >= t)
        {
            if (buses[i].first < time)
            {
                time = buses[i].first;
                bus = i;
            }
        }
        else
        {
            int cycle = (t - buses[i].first + buses[i].second - 1) / buses[i].second;
            int curTime = buses[i].first + cycle * buses[i].second;
            if (curTime < time)
            {
                time = curTime;
                bus = i;
            }
        }
    }
    cout << (bus + 1);
    return 0;
}