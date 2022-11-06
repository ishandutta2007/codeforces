#include <bits/stdc++.h>

using namespace std;

const int LOG = 30;
const int MAXN = 1E5;
int a[MAXN];
int b[MAXN];
map<int, int> mp1[LOG + 1];
map<int, int> mp2[LOG + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, y1;
    cin >> n >> y1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m, y2;
    cin >> m >> y2;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 1; i <= LOG; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int mod = a[j] & ((1 << i) - 1);
            if (mp1[i].count(mod))
                mp1[i][mod]++;
            else
                mp1[i][mod] = 1;
        }
        for (int j = 0; j < m; j++)
        {
            int mod = b[j] & ((1 << i) - 1);
            if (mp2[i].count(mod))
                mp2[i][mod]++;
            else
                mp2[i][mod] = 1;
        }
    }
    int ans = 1;
    int ptr = 0;
    for (int i = 0; i < n; i++)
    {
        while (ptr < m && b[ptr] < a[i])
            ptr++;
        if (a[i] == b[ptr])
            ans = 2;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= LOG; j++)
        {
            int mod = a[i] & ((1 << j) - 1);
            int mod2 = (mod + (1 << (j - 1))) & ((1 << j) - 1);
            ans = max(ans, mp1[j][mod] + (mp2[j].count(mod2) ? mp2[j][mod2] : 0));
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= LOG; j++)
        {
            int mod = b[i] & ((1 << j) - 1);
            int mod2 = (mod + (1 << (j - 1))) & ((1 << j) - 1);
            ans = max(ans, mp2[j][mod] + (mp1[j].count(mod2) ? mp1[j][mod2] : 0));
        }
    }
    cout << ans << endl;
    return 0;
}