#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int main()
{
    cin >> n;
    cin >> s;
    if (s[0]=='S' && s[n-1]=='F') {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}