#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<int, int> q[30][100000];

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i], q[0][i] = make_pair(a[i], a[i]);
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            q[j][i].first = min(q[j - 1][i].first, q[j - 1][i + (1 << (j - 1))].first), q[j][i].second = max(q[j - 1][i].second, q[j - 1][i + (1 << (j - 1))].second);
    int l = 0, r = n + 1;
    while (r - l > 1){
        int m = (l + r) / 2;
        bool is = 0;
        int st = 0, val = 1;
        while (val * 2 <= m)
            val *= 2, st++;
        for (int i = 0; i + m <= n && !is; i++)
            if (max(q[st][i].second, q[st][i + m - (1 << st)].second) - min(q[st][i].first, q[st][i + m - (1 << st)].first) <= 1)
                is = 1;
        if (is)
            l = m;
        else
            r = m;
    }
    cout << l;
}