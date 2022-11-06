#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<int> v(4);
    while (t--)
    {
        for (int i = 0; i < 4; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        cout << v[0] * v[2] << "\n";
    }
    return 0;
}