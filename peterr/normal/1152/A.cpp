#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int evenK = 0, oddK = 0, evenC = 0, oddC = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
            evenC++;
        else
            oddC++;
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
            evenK++;
        else
            oddK++;
    }
    cout << min(oddK, evenC) + min(evenK, oddC);
    return 0;
}