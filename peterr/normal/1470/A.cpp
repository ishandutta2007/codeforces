#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int freq[MAXN + 1];
int a[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        fill(freq + 1, freq + m + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x]++;
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> a[i];
        }
        long long ans = 0;
        priority_queue<int> pq;
        for (int i = m; i >= 1; i--)
        {
            for (int j = 0; j < freq[i]; j++)
            {
                ans += a[i];
                pq.push(a[i]);
            }
            if (!pq.empty() && a[i] < pq.top())
            {
                ans -= pq.top() - a[i];
                pq.pop();
                pq.push(a[i]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}