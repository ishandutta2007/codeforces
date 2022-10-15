#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a = 0, b, n, m, i, j;
ll enterord[100001], exitord[100001], exitordbycar[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> enterord[i];
    }
    for (i = 1; i <= n; i++)
    {
        cin >> m;
        exitord[i] = m;
        exitordbycar[m] = i;
    }
    j = n;
    for (i = n; i >= 1; i--)
    {
        while ((exitord[j] == -1) and (j != 0))
            j--;
        if ((exitord[j] == enterord[i]))
            j--;
        else
        {
            a++;
            exitord[exitordbycar[enterord[i]]] = -1;
        }
    }
    cout << a;
}