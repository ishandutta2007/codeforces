#include <bits/stdc++.h>

using namespace std;
int w, n;
long long dif, t[200002], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, dif=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (i>1) dif+=abs(t[i]-t[i-1]);
        }
        maxi=max(abs(t[1]-t[2]), abs(t[n]-t[n-1]));
        for (int i=2; i<n; i++) {
            maxi=max(maxi, abs(2*t[i]-t[i-1]-t[i+1])-abs(t[i-1]-t[i+1]));
        }
        cout << dif-maxi << "\n";
    }
    return 0;
}
/*
1
4
9 6 7 5
*/