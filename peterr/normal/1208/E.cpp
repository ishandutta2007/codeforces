#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
vector<int> a[MAXN];
long long ans[MAXN + 2];

int main()
{
    int n, w;
    cin >> n >> w;
    w += 2;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        a[i] = vector<int>(l + 2);
        a[i][0] = 0;
        for (int j = 1; j <= l; j++)
            cin >> a[i][j];
        a[i][l + 1] = 0;
    }
    long long del = 0;
    for (int i = 0; i < n; i++)
    {
        int l = (int) a[i].size();
        if (2 * l <= w)
        {
            int mx = a[i][0];
            for (int j = 1; j < l; j++)
                mx = max(mx, a[i][j]);
            del += mx;
            int pref = a[i][0];
            for (int j = 0; j < l; j++)
            {
                pref = max(pref, a[i][j]);
                ans[j] += pref - mx;
            }
            pref = a[i][l - 1];
            for (int j = 0; j < l; j++)
            {
                pref = max(pref, a[i][l - j - 1]);
                ans[w - j - 1] += pref - mx;
            }
        }
        else
        {
            deque<pair<int, int>> dq;
            int len = w - l + 1;
            int right = 0;
            int left = -len + 1;
            while (right < w)
            {
                if (right < l)
                {
                    int cur = a[i][right];
                    while (!dq.empty() && cur >= dq.back().first)
                        dq.pop_back();
                    dq.push_back(make_pair(cur, right));
                }
                if (left - 1 >= 0)
                {
                    if (!dq.empty() && dq.front().second == left - 1)
                        dq.pop_front();
                }
                ans[right] += dq.front().first;
                right++;
                left++;
            }
        }
    }
    for (int i = 1; i < w - 1; i++)
        cout << ans[i] + del << " ";
    cout << endl;
    return 0;
}