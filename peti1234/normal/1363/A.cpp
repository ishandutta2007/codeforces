#include <bits/stdc++.h>

using namespace std;
int w, n, k, o;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, o=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            o+=x%2;
        }
        if (!o || (o==n && k%2==0) || (n==k && o%2==0)) cout << "No" << "\n";
        else cout << "Yes" << "\n";
    }
    return 0;
}