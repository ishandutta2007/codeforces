#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n;
        string s;
        cin >> n >> s;
        for (int i=0; i<n; i++) cout << s[n-1];
        cout << "\n";
    }
    return 0;
}