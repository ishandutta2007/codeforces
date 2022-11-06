#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> pos[MAXN + 2];
int ans[MAXN];
bool seen[MAXN + 2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        y -= x;
        for (int i = 1; i <= n + 1; i++)
        {
            pos[i].clear();
        }
        fill(seen + 1, seen + n + 2, false);
        for (int i = 0; i < n; i++)
        {
            int b;
            cin >> b;
            seen[b] = true;
            pos[b].push_back(i);
        }
        for (int i = 1; i <= n + 1; i++)
        {
            if (!seen[i])
            {
                fill(ans, ans + n, i);
                break;
            }
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 1; i <= n + 1; i++)
        {
            if (pos[i].size())
            {
                pq.push(make_pair((int) pos[i].size(), i));
            }
        }
        for (int i = 0; i < x; i++)
        {
            pair<int, int> pr = pq.top();
            pq.pop();
            pq.push(make_pair(pr.first - 1, pr.second));
            int ind = pos[pr.second].back();
            pos[pr.second].pop_back();
            ans[ind] = pr.second;
        }
        if (pq.empty() || min(pq.top().first, n - x - pq.top().first) + n - x - pq.top().first >= y)
        {
            vector<tuple<int, int, int>> vec;
            while (!pq.empty())
            {
                pair<int, int> pr = pq.top();
                pq.pop();
                vec.push_back(make_tuple(pr.first, pr.first, pr.second));
            }
            int ptr1 = 0;
            int ptr2 = 1;
            while (y)
            {
                int amt = min(min(y, get<0>(vec[ptr1])), get<1>(vec[ptr2]));
                get<0>(vec[ptr1]) -= amt;
                get<1>(vec[ptr2]) -= amt;
                y -= amt;
                int target = get<2>(vec[ptr2]);
                while (amt--)
                {
                    int ind = pos[target].back();
                    pos[target].pop_back();
                    ans[ind] = get<2>(vec[ptr1]);
                }
                if (get<1>(vec[ptr2]) == 0)
                    ptr2++;
                if (ptr2 == (int) vec.size())
                    ptr2 = 0;
                if (get<0>(vec[ptr1]) == 0 || (ptr1 == 0 && ptr2 == 0))
                    ptr1++;
            }
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << " \n"[i == n - 1];
            }
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}