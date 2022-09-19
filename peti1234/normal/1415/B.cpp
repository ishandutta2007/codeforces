#include <bits/stdc++.h>

using namespace std;
const int c=102;
int w, t[c], n, k, maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, maxi=0;
        for (int i=1; i<c; i++) t[i]=0;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            if (i%k==t[x]%k) t[x]++, maxi=max(maxi, t[x]);
        }
        cout << (n-maxi+k-1)/k << "\n";
    }
    return 0;
}