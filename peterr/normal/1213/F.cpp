#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int p[MAXN];
int q[MAXN];
int pPos[MAXN + 1];
int qPos[MAXN + 1];
int ans[MAXN + 1];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        pPos[p[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        qPos[q[i]] = i;
    }
    int last1 = 0;
    int last2 = qPos[p[0]];
    int cnt = 0;
    while (last1 < n)
    {
        int start = last1;
        while (last1 != last2)
        {
            last1++;
            last2 = max(last2, qPos[p[last1]]);
        }
        for (int i = start; i <= last1; i++)
        {
            int x = p[i];
            ans[x] = min(25, cnt);
        }
        cnt++;
        last1++;
        if (last1 < n)
            last2 = max(last2, qPos[p[last1]]);
    }
    if (cnt >= k)
    {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
            cout << (char) ('a' + ans[i]);
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}