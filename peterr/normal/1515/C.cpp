#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m >> x;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 1; i <= m; i++)
        {
            pq.push({0, i});
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            int h;
            cin >> h;
            pair<int, int> pr = pq.top();
            pq.pop();
            cout << pr.second << " ";
            pq.push({h + pr.first, pr.second});
        }
        cout << "\n";
    }
    return 0;
}