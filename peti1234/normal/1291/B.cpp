#include <bits/stdc++.h>

using namespace std;
int w, n, q, s, x;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, q=0, s=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            q+=x<min(i-1, n-i);
            if ((x==i-1 && 2*i==n) || (x==n-i && 2*i==n+2)) s++;
        }
        if (q==0 && s<2) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}