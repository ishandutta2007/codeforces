#include <bits/stdc++.h>

using namespace std;
int w, s, n;
int main()
{
    cin >> w;
    while (w--) {
        cin >> s;
        n=sqrt(s);
        if (n*n!=s) {
            n++;
        }
        cout << n << "\n";
    }
    return 0;
}