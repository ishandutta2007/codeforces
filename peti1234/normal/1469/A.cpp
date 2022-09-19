#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> s, n=s.size();
        cout << (n%2==0 && s[0]!=')' && s[n-1]!='('? "YES" : "NO") << "\n";
    }
    return 0;
}