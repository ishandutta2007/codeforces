#include <bits/stdc++.h>

using namespace std;

int main()
{
    string aaa = "";
    string bbb = "";
    for (int i = 0; i < 300; i++)
    {
        aaa += 'a';
        bbb += 'b';
    }
    int s, t;
    cout << aaa << endl;
    cout.flush();
    cin >> s;
    if (s == 0)
        return 0;
    cout << bbb << endl;
    cout.flush();
    cin >> t;
    if (t == 0)
        return 0;
    int n = 600 - (s + t);
    int b = s - (300 - n);
    string st = "";
    for (int i = 0; i < n; i++)
        st += 'a';
    string ans = "";
    int numB = 0;
    for (int i = 0; i < n - 1; i++)
    {
        st[i] = 'b';
        cout << st << endl;
        st[i] = 'a';
        cout.flush();
        int x;
        cin >> x;
        if (x == 0)
            return 0;
        if (x == b - 1)
            ans += 'b';
        else
            ans += 'a';
        numB += ans[i] == 'b';
    }
    if (numB < b)
        ans += 'b';
    else
        ans += 'a';
    cout << ans << endl;
    cout.flush();
    int y;
    cin >> y;
    return 0;
}