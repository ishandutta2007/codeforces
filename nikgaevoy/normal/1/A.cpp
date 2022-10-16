#include <iostream>

using namespace std;

int main ()
{
    std::ios_base::sync_with_stdio (false);

    int n, m, a;

    cin >> n >> m >> a;
    n = ((n - 1) / a) + 1;
    m = ((m - 1) / a) + 1;


    cout << (long long) n * m << endl;

    return 0;
}