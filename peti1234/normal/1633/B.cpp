#include <bits/stdc++.h>

using namespace std;
int w, n, a, b;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();
        for (int i=0; i<n; i++) {
            if (s[i]=='0') a++;
            else b++;
        }
        if (a==b) a--;
        cout << min(a, b) << "\n";
        a=0, b=0;
    }
    return 0;
}