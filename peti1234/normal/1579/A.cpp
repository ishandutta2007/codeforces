#include <bits/stdc++.h>

using namespace std;
string s;
int w, a, b, c;
int main()
{
    cin >> w;
    while (w--) {
        cin >> s;
        for (auto x:s) {
            if (x=='A') a++;
            if (x=='B') b++;
            if (x=='C') c++;
        }
        if ((a+b+c)%2==0 && a+c==b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        a=b=c=0;
    }
    return 0;
}