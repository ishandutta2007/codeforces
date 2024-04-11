#include <bits/stdc++.h>

using namespace std;
int w, n, k, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, a=abs(n-k), b=INT_MAX;
        if (n>=k) b=(n-k)%2;
        cout << min(a, b) << "\n";
    }
    return 0;
}