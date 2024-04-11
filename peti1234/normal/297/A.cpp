#include <bits/stdc++.h>

using namespace std;
int a, b;
string x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> x >> y;
    for (int i=0; i<x.size(); i++) a+=(x[i]=='1');
    for (int i=0; i<y.size(); i++) b+=(y[i]=='1');
    a+=a%2;
    if (a>=b) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}