#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        int n=s.size();
        if (n%2==0 && s.substr(0, n/2)==s.substr(n/2, n/2)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}