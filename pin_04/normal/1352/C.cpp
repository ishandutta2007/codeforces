#include <iostream>

using namespace std;

int main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        int d = k / (n - 1);
        int res = d * n;
        k -= d * (n - 1);
        if (!k) cout << res - 1 << "\n";
        else cout << res + k << "\n";
    }
    return 0;
}