#include<bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        int n, k;
        cin >> n >> k;
        if (k % 3 != 0)
        {
            if (n % 3 == 0)
            {
                cout << "Bob" << endl;
            }
            else
            {
                cout << "Alice" << endl;
            }
        }
        else
        {
            n = n % (k + 1);
            if (n == k)
            {
                cout << "Alice" << endl;
            }
            else
            {
                if (n % 3 == 0)
                {
                    cout << "Bob" << endl;
                }
                else
                {
                    cout << "Alice" << endl;
                }
            }
        }
    }
}