#include <bits/stdc++.h>

using namespace std;
int n, k;
string s;
int t[101];
int main()
{
    cin >> n >> k;
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        t[s[i]-'a']++;
    }
    for (int i=0; i<=100; i++) {
        if (t[i]>k) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}