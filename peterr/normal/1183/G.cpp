#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
pair<int, int> type[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    stringstream ss;
    while (q--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a, f;
            cin >> a >> f;
            type[a].first++;
            if (f)
                type[a].second++;
        }

        sort(type + 1, type + n + 1);
        /*
        cout << "test" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << type[i].first << " " << type[i].second << endl;
        }
        */
        int index = n;
        priority_queue<int> give;
        int ans1 = 0, ans2 = 0;
        for (int freq = n; freq > 0; freq--)
        {
            while (index > 0 && type[index].first == freq)
                give.push(type[index--].second);
            if (!give.empty())
            {
                ans1 += freq;
                ans2 += min(freq, give.top());
                give.pop();
            }
        }
        ss << ans1 << " " << ans2 << endl;
        for (int i = 1; i <= n; i++)
            type[i] = {0, 0};
    }
    cout << ss.str();
    return 0;
}