#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ind = 0;
    for (int i = 30; i >= 0; i--)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] & (1 << i))
            {
                cnt++;
                ind = j;
            }
        }
        if (cnt == 1)
            break;
    }
    cout << a[ind];
    for (int i = 0; i < n; i++)
    {
        if (i != ind)
            cout << " " << a[i];
    }
    cout << endl;
    return 0;
}