#include <bits/stdc++.h>

using namespace std;
int w, n, x, e, sum, p;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> x, e=0, sum=0;
        for (int i=1; i<=n; i++) {
            cin >> p, e+=(p==x);
            sum+=p;
        }
        if (e==n) cout << 0;
        else if (sum==n*x || e) cout << 1;
        else cout << 2;
        cout << "\n";
    }
    return 0;
}