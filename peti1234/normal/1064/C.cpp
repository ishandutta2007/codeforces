#include <bits/stdc++.h>

using namespace std;
int a;
string s;
int main()
{
    cin >> a  >> s;
    sort(s.begin(), s.end());
    for (int i=0; i<a; i++) {
        cout << s[i];
    }
    return 0;
}