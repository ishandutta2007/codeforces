#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    std::ios_base::sync_with_stdio (false);

    int n;
    long long a;

    cin >> n >> a;

    vector<int> d(n);
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        sum += d[i];
    }

    for (int i = 0; i < n; i++)
        cout << (max(0ll, a - (sum - d[i] + 1)) + max(0ll, (n - 1ll + d[i]) - a)) << ' ';

    cout << endl;

    return 0;
}