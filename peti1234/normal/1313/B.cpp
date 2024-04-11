#include <bits/stdc++.h>

using namespace std;
int w, a, b, n;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> a >> b;
        cout << max(1, min(n, n-(2*n-a-b-1))) << " " << min(n, a+b-1) << "\n";
    }
    return 0;
}