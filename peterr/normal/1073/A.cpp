#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int index = -1;
    for (int i = 0; i < (int) s.length() - 1; i++)
    {
        if (s[i] != s[i + 1])
            index = i;
    }
    if (index == -1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl << s.substr(index, 2) << endl;
    return 0;
}