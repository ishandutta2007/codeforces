#include <bits/stdc++.h>

using namespace std;
int n, db=1;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i=1; i<n; i++) {
        if (s[i]!=s[i-1]) db++;
    }
    cout << min(n, db+2) << "\n";
    return 0;
}