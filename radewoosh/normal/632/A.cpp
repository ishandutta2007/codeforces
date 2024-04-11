#include <bits/stdc++.h>
using namespace std;

int n, p;

long long wyn;

long long ma=1;

string wcz[107];

int main()
{
    cin >> n >> p;
    for (int i=1; i<=n; i++)
    cin >> wcz[i];
    wyn=p/2;
    for (int i=n-1; i; i--)
    {
        if (wcz[i].size()==4)
        {
            wyn+=ma*p;
            ma*=2;
        }
        else
        {
            wyn+=ma*p+p/2;
            ma*=2;
            ma++;
        }
    }
    cout << wyn << endl;
    return 0;
}