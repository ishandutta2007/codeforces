#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <ctime>

using namespace std;
const int inf = int (1e9 + 7);

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    cout << n / 2 << endl;

    while (n > 3)
    {
        cout << "2 ";
        n -= 2;
    }
    cout << n << endl;

    return 0;
}