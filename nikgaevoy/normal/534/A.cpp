#include <iostream>
#include <vector>

using namespace std;

const vector<string> res = {"0\n", "1\n1 ", "1\n1 ", "2\n1 3 "};

int main ()
{
    std::ios_base::sync_with_stdio (false);

    int n;

    cin >> n;

    if (n > 3)
    {
        cout << n << endl;
        for (int i = (n - 1) | 1; i > 0; i -= 2)
            cout << i << ' ';

        for (int i = n & (-1 ^ 1); i > 0; i -= 2)
            cout << i << ' ';
    }
    else
        cout << res[n];

    return 0;
}