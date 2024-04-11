#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;


int main()
{
    int n, k;
    cin >> n >> k;
    if (k == 2 && n >= 5)
    {
        cout << n - 1 << endl;
        for (int i = 1; i < n; i++)
            cout << i << " " << i + 1 << endl;
        return 0;
    }
    if (k == 3 && n >= 4)
    {
        cout << n - 1 << endl;
        cout << "1 2" << endl;
        cout << "2 3" << endl;
        for (int i = 4; i <= n; i++)
            cout << "1 " << i << endl;
        return 0;
    }
    cout << -1;
    return 0;
}