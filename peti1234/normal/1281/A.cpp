#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s;
        if (s.back()=='o') {
            cout << "FILIPINO\n";
        }
        if (s.back()=='u') {
            cout << "JAPANESE\n";
        }
        if (s.back()=='a') {
            cout << "KOREAN\n";
        }
    }
    return 0;
}