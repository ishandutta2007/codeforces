#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;
string s[MAXN];
string t[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0 ; i < m; i++)
        cin >> t[i];
    int q;
    cin >> q;
    while (q--)
    {
        int y;
        cin >> y;
        y--;
        cout << s[y % n] + t[y % m] << endl;
    }
    return 0;
}