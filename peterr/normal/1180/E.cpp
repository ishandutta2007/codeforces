#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300000;
const int SEGLEN = (1 << 20);
int a[MAXN];
int b[MAXN];
pair<int, int> bal[2 * SEGLEN];


void increment(int a, int b, int i, int x, int y, int amt)
{
    if (a > y || b < x)
        return;
    if (i >= SEGLEN)
    {
        bal[i].first += amt;
        return;
    }
    if (bal[i].second != 0)
    {
        bal[i].first += bal[i].second;
        bal[i * 2].second += bal[i].second;
        bal[i * 2 + 1].second += bal[i].second;
        bal[i].second = 0;
    }
    if (x >= a && y <= b)
    {
        bal[i].second += amt;
    }
    else
    {
        int mid = (x + y) / 2;
        increment(a, b, i * 2, x, mid, amt);
        increment(a, b, i * 2 + 1, mid + 1, y, amt);
        bal[i].first = max(bal[i * 2].first + bal[i * 2].second, bal[i * 2 + 1].first + bal[i * 2 + 1].second);
    }
}

int findMax(int i, int x, int y)
{
    if (i >= SEGLEN)
    {
        if (bal[i].first + bal[i].second > 0)
        {
            return i - SEGLEN;
        }
        else
        {
            return -1;
        }
    }
    if (bal[i].second != 0)
    {
        bal[i].first += bal[i].second;
        bal[i * 2].second += bal[i].second;
        bal[i * 2 + 1].second += bal[i].second;
        bal[i].second = 0;
    }
    if (bal[i].first <= 0)
        return -1;
    int mid = (x + y) / 2;
    int ans1 = findMax(i * 2 + 1, mid + 1, y);
    if (ans1 != -1)
        return ans1;
    return findMax(i * 2, x, mid);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        increment(0, a[i], 1, 0, SEGLEN - 1, 1);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        increment(0, b[i], 1, 0, SEGLEN - 1, -1);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int type, index, x;
        cin >> type >> index >> x;
        index--;
        if (type == 1)
        {
            if (x > a[index])
                increment(a[index] + 1, x, 1, 0, SEGLEN - 1, 1);
            else if (x < a[index])
                increment(x + 1, a[index], 1, 0, SEGLEN - 1, -1);
            a[index] = x;
        }
        else
        {
            if (x > b[index])
                increment(b[index] + 1, x, 1, 0, SEGLEN - 1, -1);
            else if (x < b[index])
                increment(x + 1, b[index], 1, 0, SEGLEN - 1, 1);
            b[index] = x;
        }
        cout << findMax(1, 0, SEGLEN - 1) << endl;
    }
    return 0;
}