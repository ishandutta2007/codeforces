#include<iostream>

using namespace std;
const int N = 100000;

int main()
{
    int a[N+10],f[N+10];
    int cur,n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[0] = 0; cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur += -a[i];
        f[i] = max(f[i-1] + a[i] , cur);
    }
    int ans = f[n]; cur = 0;
    for (int i = n; i >= 1; i--)
    {
        cur += -a[i];
        ans = max(ans , f[i-1] + cur);
    }
    cout << ans << endl;
    return 0;

}