#include<iostream>

using namespace std;

int main()
{
    char c1,c2;
    int n;
    cin >> n;
    if (n % 2 == 1) { cout << "-1"; return 0; }
    for (int k = 1; k <= n; k++)
    {
        if (k % 2 == 1) { c1 = 'w'; c2 = 'b'; } else { c1 = 'b'; c2 = 'w'; }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int res = min(i - 1, j - 1);
                res = min(res, n - i); res = min(res, n - j);
                if (res % 2 == 1) cout << c1; else cout << c2;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}