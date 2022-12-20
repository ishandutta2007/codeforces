#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        string a,b;
        cin >> a >> b;
        int len = a.size() * b.size() / __gcd(a.size(), b.size());

        string str = "";
        while (str.size() < len)
            str += a;

        string tmp = "";
        while (tmp.size() < len)
            tmp += b;
        if (str == tmp)
            cout << str << "\n";
        else
            cout << -1 << "\n";

    }
    return 0;
}