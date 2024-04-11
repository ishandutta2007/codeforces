#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a>b) swap(a, b);
    if (a>c) swap(a, c);
    if (b>c) swap(b, c);
    cout << max(0, d+a-b)+max(0, d+b-c) << "\n";
    return 0;
}