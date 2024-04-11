#include <iostream>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;

    int ops = 0;
    for (int i = 1; i <= y; i++)
    {
        if (s[n-i] == '1')
            ops++;
    }
    if (s[n-y-1] == '0')
        ops++;
    for (int i = y + 2; i <= x; i++)
    {
        if (s[n-i] == '1')
            ops++;
    }
    cout << ops;

    return 0;
}