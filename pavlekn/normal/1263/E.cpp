#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int mx[8 * MAXN];
int mn[8 * MAXN];
int add[8 * MAXN];

void push(int v, int l, int r)
{
    add[2 * v + 1] += add[v];
    add[2 * v + 2] += add[v];
    mn[v] += add[v];
    mx[v] += add[v];
    add[v] = 0;
}

void update(int v, int i, int l, int r, int d)
{
    push(v, l, r);
    if (i <= l)
    {
        add[v] += d;
        push(v, l, r);
        return;
    }
    if (r <= i)
    {
        return;
    }
    update(2 * v + 1, i, l, (l + r) / 2, d);
    update(2 * v + 2, i, (l + r) / 2, r, d);
    mn[v] = min(mn[2 * v + 1], mn[2 * v + 2]);
    mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
    push(v, l, r);
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    vector<char> a(MAXN, 0);
    int sm = 0;
    int sz = 0;
    for (auto el : s)
    {
        if (el == 'R')
        {
            ++i;
        }
        else if (el == 'L')
        {
            --i;
            i = max(i, 0);
        }
        else
        {
            int d = 0;
            if (a[i] == '(')
            {
                --sm;
                --d;
            }
            else if (a[i] == ')')
            {
                ++sm;
                ++d;
            }
            if (el == '(')
            {
                ++sm;
                ++d;
            }
            else if (el == ')')
            {
                --sm;
                --d;
            }
            a[i] = el;
            update(0, i, 0, MAXN, d);
        }
        if (sm == 0 && mn[0] >= 0)
        {
            cout << mx[0] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
    cout << endl;
    return 0;
}