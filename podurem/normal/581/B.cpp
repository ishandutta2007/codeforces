#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        b[i] = max(b[i + 1], a[i]);
    for (int i = 0; i < n; i++)
        if (a[i] == b[i] && b[i] != b[i + 1])
            cout << 0 << " ";
        else
            cout << b[i] - a[i] + 1 << " ";
}