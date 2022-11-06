#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1E5;
pair<int, int> ans[MAXN];
int cycle[MAXN];

int main()
{
    int n, q;
    cin >> n >> q;
    list<int> deq;
    int big = -1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        deq.push_back(a);
        big = max(big, a);
    }
    int count = 1;
    while (deq.front() != big)
    {
        auto it = deq.begin();
        it++;
        int sec = *it;
        ans[count].first = deq.front();
        ans[count].second = sec;
        if (deq.front() < sec)
        {
            deq.push_back(deq.front());
            deq.erase(deq.begin());
        }
        else
        {
            deq.push_back(sec);
            deq.erase(it);
        }
        count++;
    }
    ans[count].first = deq.front();
    ans[count].second = *(++deq.begin());
    int index = 0;
    for (auto it = ++deq.begin(); it != deq.end(); it++)
    {
        cycle[index++] = *it;
    }

    for (int i = 0; i < q; i++)
    {
        long long m;
        cin >> m;
        if (m <= count)
        {
            cout << ans[m].first << " " << ans[m].second << endl;
        }
        else
        {
            m -= count;
            cout << big << " " << cycle[(m) % (n - 1)] << endl;
        }
    }
    return 0;
}