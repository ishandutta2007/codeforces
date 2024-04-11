#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        cout << n << "\n";
        for (int i=1; i<n; i++) cout << i << " ";
        cout << "\n";
    }
    return 0;
}