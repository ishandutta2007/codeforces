#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, m;
        cin >> h >> m;
        int t = h * 60 + m;
        if (t == 0)
            cout << 0 << endl;
        else
            cout << 24 * 60 - t << endl;
    }
    return 0;
}