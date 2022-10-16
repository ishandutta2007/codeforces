#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <complex>
#include <cstdio>
#include <ctime>

using namespace std;
const int inf = int (1e9 + 7);

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    complex<int> v[3];

    for (int i = 0; i < 3; i++)
    {
        int a, b;

        cin >> a >> b;

        v[i].real (a);
        v[i].imag(b);
    }

    cout << 3 << endl;

    for (int i = 0; i < 3; i++)
    {
        complex<int> sum;

        for (int j = 0; j < 3; j++)
            if (i != j)
                sum += v[j];

        complex<int> ans = sum - v[i];

        cout << ans.real () << ' ' << ans.imag () << endl;
    }

    return 0;
}