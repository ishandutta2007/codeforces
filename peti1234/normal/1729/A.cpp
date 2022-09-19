#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int a, b, c;
        cin >> a >> b >> c;
        int s=a, t=abs(b-c)+c;
        if (s<t) cout << 1;
        if (s>t) cout << 2;
        if (s==t) cout << 3;
        cout << "\n";
    }
    return 0;
}