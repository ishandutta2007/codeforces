#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
bool served[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    priority_queue<pair<int, int>> pq;
    int ptr = 1;
    int cur = 1;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            pq.push({x, -cur});
            cur++;
        }
        else if (t == 2)
        {
            while (served[ptr])
                ptr++;
            cout << ptr << " ";
            served[ptr] = true;
        }
        else
        {
            while (served[-pq.top().second])
                pq.pop();
            cout << -pq.top().second << " ";
            served[-pq.top().second] = true;
        }
    }
    return 0;
}