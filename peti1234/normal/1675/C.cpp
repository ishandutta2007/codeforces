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
        int n=s.size(), a=0, b=n-1;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='1') a=i;
            if (s[i]=='0') b=min(b, i);
        }
        cout << (b-a+1) << "\n";
    }
    return 0;
}