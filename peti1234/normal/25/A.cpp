#include <bits/stdc++.h>

using namespace std;
int n, o, e, x, y, s;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> s;
        if (s%2) o++, x=i;
        else e++, y=i;
    }
    cout << (o==1 ? x : y) << "\n";
    return 0;
}