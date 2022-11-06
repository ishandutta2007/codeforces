#include <iostream>

using namespace std;

int main()
{
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    bool same = false;
    while (a != x && b != y)
    {
        a++;
        b--;
        if (a == n+1)
            a = 1;
        if (b == 0)
            b = n;
        if (a == b)
            same = true;
    }
    if (a == b)
        same = true;
    if (same)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}