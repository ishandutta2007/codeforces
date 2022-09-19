#include <bits/stdc++.h>

using namespace std;
int w, n;
long long k, t[200002], maxi, m2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, k--, maxi=-INT_MAX, m2=0;
        for (int i=1; i<=n; i++) cin >> t[i], maxi=max(maxi, t[i]);
        for (int i=1; i<=n; i++) t[i]=maxi-t[i], m2=max(m2, t[i]);
        if (k%2) for (int i=1; i<=n; i++) t[i]=m2-t[i];
        for (int i=1; i<=n; i++) cout << t[i] << " ";
        cout << "\n";
    }
    return 0;
}