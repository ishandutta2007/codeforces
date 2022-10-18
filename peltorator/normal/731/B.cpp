#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

vector<int> a;

int main()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            cout << "NO";
            return 0;
        }
        if (a[i] % 2 == 1 && i + 1 < n)
            a[i + 1]--;
        else if (a[i] % 2 == 1 && i + 1 == n)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}