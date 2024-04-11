#include <iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        int lo = 1e8 + 5, hi = -1;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            lo = min(lo, a);
            hi = max(hi, a);
        }
        if (lo + k < hi - k)
            cout << -1 << endl;
        else
            cout << (lo + k) << endl;
    }
    return 0;
}