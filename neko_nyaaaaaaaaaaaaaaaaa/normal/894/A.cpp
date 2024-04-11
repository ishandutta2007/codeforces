#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int res = 0;
    cin >> s;
    for (int i = 0; i < char(s.length() - 2); i++)
        for (int j = i + 1; j < s.length() - 1; j++)
        for (int k = j + 1; k < s.length(); k++) res += (s[i] == 'Q' and s[j] == 'A' and s[k] == 'Q');
    cout << res;
}