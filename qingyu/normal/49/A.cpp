#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    getline(cin, s);
    int n = s.length() - 1;
    while (!isalpha(s[n])) --n;
    s[n] = tolower(s[n]);
    if (s[n] == 'a' || s[n] == 'e' || s[n] == 'i' || s[n] == 'o' || s[n] == 'u' || s[n] == 'y') puts("YES");
    else puts("NO");
    return 0;
}