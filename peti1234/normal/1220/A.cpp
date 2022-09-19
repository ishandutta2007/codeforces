#include <bits/stdc++.h>

using namespace std;
string s;
int n, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='r') {
            b++;
        }
        if (s[i]=='n') {
            a++;
        }
    }
    for (int i=1; i<=a; i++) {
        cout << 1 << " ";
    }
    for (int i=1; i<=b; i++) {
        cout << 0 << " ";
    }
    return 0;
}