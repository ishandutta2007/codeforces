#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

#include <cassert>

using namespace std;

const int inf = (int)1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    cout << (3 * n) / 2 << endl;

    for (int i = 2; i <= n; i += 2)
        cout << i << ' ';
    for (int i = 1; i <= n; i += 2)
        cout << i << ' ';
    for (int i = 2; i <= n; i += 2)
        cout << i << ' ';
    cout << endl;

    return 0;
}