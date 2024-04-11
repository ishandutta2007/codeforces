#include <bits/stdc++.h>

using namespace std;
int a, b, pos;
string x="hello", y;
int main()
{
    cin >> y, a=x.size(), b=y.size();
    for (int i=0; i<b; i++) {
        if (pos<a && y[i]==x[pos]) {
            pos++;
        }
    }
    if (pos==a) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}