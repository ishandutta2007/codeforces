#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9;
const int MAXN = 2E5;
int a[MAXN];

bool check(int n, int k, int d)
{
    queue<pair<int, int>> q;
    deque<pair<int, int>> deq;
    q.push({0, 0});
    k--;
    int ptr = 0;
    while (ptr < n && k > 0 && (!q.empty() || !deq.empty()))
    {
        if (q.empty())
        {
            q.push(deq.front());
            deq.pop_front();
            while (!deq.empty() && deq.front().first == q.front().first)
            {
                q.push(deq.front());
                deq.pop_front();
            }
        }
        int dep = q.front().first;
        if (q.front().second && dep + 1 <= d)
            deq.push_front({dep + 1, q.front().second - 1});
        q.pop();
        k++;
        int left = (a[ptr] - 1) / 2;
        int right = a[ptr] / 2;
        ptr++;
        k -= max(0, min(left, d - (dep + 1)));
        k -= max(0, min(right, d - (dep + 1)));
        if (dep + 2 <= d)
        {
            deq.push_back({dep + 2, left - 1});
            deq.push_back({dep + 2, right - 1});
        }
    }
    return k <= 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    int ans = INF;
    for (int jump = INF >> 1; jump; jump >>= 1)
    {
        while (ans - jump >= 2 && check(n, k, ans - jump))
            ans -= jump;
    }
    if (ans == INF)
        ans = -1;
    cout << ans << "\n";
    return 0;
}