#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4E5;
int freq[MAXN];

int main()
{
    int q, x;
    cin >> q >> x;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < x; i++)
        pq.push(make_pair(0, i));
    while (q--)
    {
        int y;
        cin >> y;
        y %= x;
        freq[y]++;
        pq.push(make_pair(freq[y], y));
        while (pq.top().first != freq[pq.top().second])
            pq.pop();
        int ans = x * pq.top().first + pq.top().second;
        cout << ans << endl;
    }
    return 0;
}