#include <bits/stdc++.h>

using namespace std;

char  stk[105];

int main()
{
    //freopen("file.inp","r",stdin);
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        int cnt = 0, top = 0;
        for (char c : s)
        {
            if (top > 0 && c != stk[top])
            {
                cnt++;
                top--;
            } else {
                stk[++top] = c;
            }
        }
        cout << ((cnt % 2) ? "DA" : "NET") << "\n";
    }
    return 0;
}