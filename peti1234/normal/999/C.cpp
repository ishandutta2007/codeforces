#include <bits/stdc++.h>

using namespace std;
bool v[400000];
string s;
int n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;
    for (char c='a'; c<='z'; c++) {
        for (int i=0; i<n; i++) {
            if (k && s[i]==c) v[i]=1, k--;
        }
    }
    for (int i=0; i<n; i++) {
        if (!v[i]) cout << s[i];
    }
    cout << "\n";
    return 0;
}