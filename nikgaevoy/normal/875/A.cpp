#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <random>

#include <cassert>

using namespace std;

int ds (int n)
{
    return n ? n % 10 + ds (n / 10) : 0;
}

int main ()
{
    int n;

    cin >> n;

    vector<int> ans;

    for (int i = max (0, n - 99); i <= n; i++)
        if (i + ds (i) == n)
            ans.push_back (i);

    cout << ans.size () << endl;

    for (auto it : ans)
        cout << it << ' ';
    cout << endl;

    return 0;
}