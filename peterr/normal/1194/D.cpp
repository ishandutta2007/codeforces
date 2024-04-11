#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        if (k % 3 != 0 || k > n)
        {
            if (n % 3 != 0)
            {
                cout << "Alice" << endl;
            }
            else
            {
                cout << "Bob" << endl;
            }
        }
        else
        {
            int x = n % (k + 1);
            if (x == k)
            {
                cout << "Alice" << endl;
            }
            else if (x % 3 != 0)
            {
                cout << "Alice" << endl;
            }
            else
            {
                cout << "Bob" << endl;
            }
        }
    }
    return 0;
}