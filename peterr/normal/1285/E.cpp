#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
pair<int, int> segs[MAXN];
int ans[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        fill(ans, ans + n, 0);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        for (int i = 0 ; i < n; i++)
        {
            cin >> segs[i].first >> segs[i].second;
            pq.push(make_tuple(segs[i].first, -1, i));
            pq.push(make_tuple(segs[i].second, 1, i));
        }
        set<int> used;
        int segments = 0;
        int depth = 0;
        bool flag = false;
        tuple<int, int, int> prev = make_tuple(0, 0, 0);
        while (!pq.empty())
        {
            tuple<int, int, int> event = pq.top();
            pq.pop();
            int x = get<0>(event);
            int ind = get<2>(event);
            int del = -get<1>(event);
            if (depth == 1 && get<2>(prev) == ind)
                ans[ind] = -1;
            if (depth == 0)
                segments++;
            if (flag)
            {
                if (depth == 1 && del == 1)
                {
                    ans[*used.begin()]++;
                }
                flag = false;
            }
            if (depth == 2 && del == -1)
            {
                flag = true;
            }
            if (del == 1)
                used.insert(ind);
            else
                used.erase(ind);
            depth += del;
            prev = event;
        }
        int big = segments - 1;
        for (int i = 0; i < n; i++)
            big = max(big, segments + ans[i]);
        cout << big << endl;
    }
    return 0;
}