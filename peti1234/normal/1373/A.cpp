#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a<c) cout << "1\n";
        else cout << "-1\n";
        if (a*b>c) cout << b << "\n";
        else cout << "-1\n";
    }
    return 0;
}