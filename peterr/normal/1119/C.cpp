#include <bits/stdc++.h>
#define f(i, a, b) for(int i = a; i < b; i++)

using namespace std;

const int MAXN = 500;
bool a[MAXN][MAXN];
bool b[MAXN][MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    f(i, 0, n)
        f(j, 0, m)
            cin >> a[i][j];
    f(i, 0, n)
        f(j, 0, m)
            cin >> b[i][j];
    bool possible = true;
    f(i, 0, n)
    {
        int errors = 0;
        f(j, 0, m)
        {
            if (a[i][j] != b[i][j])
                errors++;
        }
        if (errors % 2 == 1)
            possible = false;
    }
    f(j, 0, m)
    {
        int errors = 0;
        f(i, 0, n)
        {
            if (a[i][j] != b[i][j])
                errors++;
        }
        if (errors % 2 == 1)
            possible = false;
    }
    if (possible)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}