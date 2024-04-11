#include <bits/stdc++.h>

using namespace std;
int w, n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m;
        if (n==1) cout << 0;
        if (n==2) cout << m;
        if (n>2) cout << 2*m;
        cout << "\n";
    }
    return 0;
}