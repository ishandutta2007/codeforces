#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int b[MAXN];
int c[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] - b[i];
        if (c[i] > 0)
            pos++;
    }
    sort(c, c + n);
    int cur = 0;
    int right = n;
    long long ans = 0;
    while (cur < n)
    {
        while (right && c[cur] + c[right - 1] > 0)
            right--;
        ans += n - right;
        cur++;
    }
    cout << (ans - pos) / 2 << endl;
    return 0;
}