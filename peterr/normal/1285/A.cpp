#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int a, b;
    a = b = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            a++;
        else
            b++;
    }
    cout << a + b + 1 << endl;
    return 0;
}