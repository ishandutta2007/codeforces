#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int t[2];
    int z[3] = { 28 % 7, 30 % 7, 31 % 7 };
    string s[2];
    cin >> s[0] >> s[1];
    for (int i = 0; i < 2; i++)
    {
        char c = s[i][0];
        if (c == 'm')
            t[i] = 1;
        if (c == 't' && s[i][1] == 'u')
            t[i] = 2;
        if (c == 'w')
            t[i] = 3;
        if (c == 't' && s[i][1] == 'h')
            t[i] = 4;
        if (c == 'f')
            t[i] = 5;
        if (c == 's' && s[i][1] == 'a')
            t[i] = 6;
        if (c == 's' && s[i][1] == 'u')
            t[i] = 7;
    }
    int k = (t[1] - t[0] + 7) % 7;
    if (k == z[0] || k == z[1] || k == z[2])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}