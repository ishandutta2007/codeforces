#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    int* s = new int[n];
    int* b = new int[m];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(s, s + n);
    sort(b, b + m);

    int shares = r / s[0];
    if (b[m-1] > s[0])
        cout << (shares * b[m - 1]) + (r % s[0]);
    else
        cout << r;
    return 0;
}