#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long sum = 0;
        long long even = 0;
        long long odd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (i & 1)
                odd += a[i] - 1;
            else
                even += a[i] - 1;
        }
        bool doOdd = odd < even;
        for (int i = 0; i < n; i++)
        {
            if ((i & 1) != doOdd)
                cout << a[i] << " ";
            else
                cout << "1 ";
        }
        cout << "\n";
    }
    return 0;
}