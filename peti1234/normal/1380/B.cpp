#include <bits/stdc++.h>

using namespace std;
int w, n, a, b, c;
string s;
char x;
int main()
{
    cin >> w;
    while(w--) {
        cin >> s, a=0, b=0, c=0, n=s.size();
        for (int i=0; i<n; i++) {
            if (s[i]=='R') a++;
            if (s[i]=='S') b++;
            if (s[i]=='P') c++;
        }
        if (a>max(b, c)) x='P';
        else if (b>c) x='R';
        else x='S';
        for (int i=0; i<n; i++) cout << x;
        cout << "\n";
    }
    return 0;
}