#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
pair<int, int> events[2 * MAXN];
int a[MAXN];

int main()
{
    int n, h, m, k;
    cin >> n >> h >> m >> k;
    int bad = 0;
    for (int i = 0; i < n; i++)
    {
        int hr, mn;
        cin >> hr >> mn;
        if (mn >= m / 2)
            mn -= m / 2;
        a[i] = mn;
        if (mn > m / 2 - k)
        {
            bad++;
            events[2 * i] = make_pair(mn - (m / 2 - k), -1);
            events[2 * i + 1] = make_pair(mn + 1, 1);
        }
        else
        {
            events[2 * i] = make_pair(mn + 1, 1);
            events[2 * i + 1] = make_pair(mn + k, -1);
        }
    }
    sort(events, events + 2 * n);
    int lowBad = bad;
    int bestTime = 0;
    int ptr = 0;
    while (ptr < 2 * n && events[ptr].first < m / 2)
    {
        int time = events[ptr].first;
        while (ptr < 2 * n && events[ptr].first == time)
        {
            bad += events[ptr].second;
            ptr++;
        }
        if (bad < lowBad)
        {
            lowBad = bad;
            bestTime = time;
        }
    }
    cout << lowBad << " " << bestTime << "\n";
    vector<int> trams;
    for (int i = 0; i < n; i++)
    {
        if (bestTime > a[i] && bestTime - a[i] < k)
        {
            trams.push_back(i + 1);
            continue;
        }
        if (a[i] > m / 2 - k + bestTime)
        {
            trams.push_back(i + 1);
            continue;
        }
    }
    for (int i = 0; i < (int) trams.size(); i++)
    {
        cout << trams[i] << " \n"[i == (int) trams.size() - 1];
    }
    return 0;
}