#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=2*n+2; i<=4*n; i+=2) cout << i << " ";
        cout << "\n";
    }
    return 0;
}