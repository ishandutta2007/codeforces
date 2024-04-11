#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int n = s1.length(), c1 = 0, c2 = 0;
    for (int i = 0; i * 2 < n; i++)
    {
        if (s1[i * 2] == s2[i * 2]) continue;
        if (s1[i * 2] == '8' && s2[i * 2] == '(') c2++;
        if (s1[i * 2] == '8' && s2[i * 2] == '[') c1++;
        if (s1[i * 2] == '(' && s2[i * 2] == '[') c2++;
        if (s1[i * 2] == '(' && s2[i * 2] == '8') c1++;
        if (s1[i * 2] == '[' && s2[i * 2] == '8') c2++;
        if (s1[i * 2] == '[' && s2[i * 2] == '(') c1++;
    }
    if (c1 == c2) puts("TIE");
    if (c1 < c2) puts("TEAM 2 WINS");
    if (c1 > c2) puts("TEAM 1 WINS");
    return 0;
}