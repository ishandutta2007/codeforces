#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(n, 0));
        int cnt = 1;
        while (!pq.empty())
        {
            pair<int, int> pr = pq.top();
            pq.pop();
            int len = pr.first;
            int ind = -pr.second;
            int pos = ind + len / 2;
            if ((len & 1) == 0)
                pos--;
            a[pos] = cnt++;
            if (pos - 1 >= ind)
            {
                pq.push(make_pair(pos - 1 - ind + 1, -ind));
            }
            if (len > 1)
            {
                pq.push(make_pair(len / 2, -pos - 1));
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}