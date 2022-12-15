#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 1e5 + 5;

int a[N];
int ans[N];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    cout << (n - 1) / 2 << "\n";
    int mid = n / 2 + 1;
    for (int i = 1; i <= n; i += 2)
    {
        ans[i] = a[mid++];
    }
    mid = 1;
    for (int i = 2; i <= n; i += 2)
    {
        ans[i] = a[mid++];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}