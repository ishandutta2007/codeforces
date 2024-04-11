#include <bits/stdc++.h>

using namespace std;
int w, t[102], n, sum, e, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, sum=0, e=1, k=1;
        for (int i=0; i<=n; i++) t[i]=0;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            t[x]++;
        }
        for (int i=0; i<n; i++) {
            if (e && t[i]) sum++;
            else e=0;
            if (k && t[i]>1) sum++;
            else k=0;
        }
        cout << sum << "\n";
    }
    return 0;
}