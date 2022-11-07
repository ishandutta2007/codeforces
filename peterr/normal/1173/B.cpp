#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = n / 2 + 1;

    cout << m << endl;
    bool right = true;
    int r = 1, c = 1;
    for (int i = 0; i < n; i++)
    {
        cout << r << " " << c << endl;
        if (right)
            c++;
        else
            r++;
        right = !right;
    }
    return 0;
}