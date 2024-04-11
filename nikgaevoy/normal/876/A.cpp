#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, a, b, c;

    cin >> n >> a >> b >> c;

    cout << (n == 1 ? 0 : min (a, b) + (n - 2) * min ({a, b, c})) << endl;

    return 0;
}