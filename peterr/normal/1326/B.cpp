#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int b[MAXN];
long long a[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    a[0] = b[0];
    long long m = a[0];
    for (int i = 1; i < n; i++)
    {
        a[i] = b[i] + m;
        m = max(m, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}