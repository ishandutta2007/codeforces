#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        string s;
        cin >> s;
        int a=0, si=s.size();
        for (int i=0; i<si; i++) a+=(s[i]=='0');
        a=min(a, si-a);
        if (a%2) cout << "DA\n";
        else cout << "NET\n";
    }
    return 0;
}