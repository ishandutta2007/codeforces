#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <complex>

#include <cassert>

using namespace std;

const int inf = (int)1e9 + 7;
const double pi = 3.14159265358979323846;

double expected_depth (const vector<vector<int>> &gr, int st = 0, int prev = -1)
{
    double ans = 0;
    int cnt = 0;

    for (auto it : gr[st])
        if (it != prev)
            cnt++, ans += 1 + expected_depth (gr, it, st);

    return ans / max (cnt, 1);
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<vector<int>> gr (n);

    for (int i = 1; i < gr.size (); i++)
    {
        int a, b;

        cin >> a >> b;
        a--;
        b--;

        gr[a].push_back (b);
        gr[b].push_back (a);
    }

    cout.precision (20);
    cout << fixed << expected_depth (gr) << endl;

    return 0;
}