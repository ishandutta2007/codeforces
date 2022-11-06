#include <iostream>

using namespace std;

const int MAXN = 3*1E5;
int c[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (c[i] != c[0])
        {
            ans = max(ans, i);
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (c[i] != c[n-1])
        {
            ans = max(ans, n - 1 - i);
            break;
        }
    }
    cout << ans;
    return 0;
}