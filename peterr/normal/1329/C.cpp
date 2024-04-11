#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 20;
pair<int, int> a[MAXN];
vector<pair<int, int>> vec;

int getInd(int pos, int n, bool del)
{
    int left = pos * 2;
    int right = left + 1;
    if (left > n)
    {
        if (del)
            a[pos].second = 0;
        return pos;
    }
    if (a[left].second == 0 && a[right].second == 0)
    {
        if (del)
            a[pos].second = 0;
        return pos;
    }
    if (a[left].second > a[right].second)
    {
        if (del)
            a[pos] = a[left];
        return getInd(left, n, del);
    }
    if (del)
        a[pos] = a[right];
    return getInd(right, n, del);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int h, g;
        cin >> h >> g;
        int n = (1 << h) - 1;
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            a[i] = make_pair(i, x);
        }
        int m = 1 << g;
        vec.clear();
        for (int i = 1; i < m; i++)
        {
            while (getInd(i, n, false) >= m)
            {
                //cout << i << " " << a[i].first << " " << a[i].second << endl;
                vec.push_back(a[i]);
                sum -= a[i].second;
                getInd(i, n, true);
            }
        }
        cout << sum << "\n";
        sort(vec.rbegin(), vec.rend());
        for (int i = 0; i < (int) vec.size(); i++)
            cout << vec[i].first << " \n"[i == (int) vec.size() - 1];
    }
    return 0;
}