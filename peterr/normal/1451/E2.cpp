#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 16;
int x[MAXN + 1];
int ans[MAXN + 1];
int where[MAXN];

int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    m[0] = 1;
    int ind1 = -1;
    int ind2 = -1;
    for (int i = 2; i <= n; i++)
    {
        cout << "XOR " << 1 << " " << i << endl;
        cin >> x[i];
        if (m.count(x[i]))
        {
            ind1 = m[x[i]];
            ind2 = i;
        }
        m[x[i]] = i;
        where[x[i]] = i;
    }
    where[0] = 1;
    if (ind1 == -1)
    {
        cout << "AND " << where[0] << " " << where[1] << endl;
        int q1, q2;
        cin >> q1;
        cout << "AND " << where[0] << " " << where[2] << endl;
        cin >> q2;
        ans[where[0]] = q1 - q1 % 2 + (q2 & 1);
        ind1 = where[0];
    }
    else
    {
        cout << "AND " << ind1 << " " << ind2 << endl;
        int q;
        cin >> q;
        ans[ind1] = q;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == ind1)
            continue;
        ans[i] = ans[ind1] ^ x[ind1] ^ x[i];
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}