#include <bits/stdc++.h>

using namespace std;
int w, n, k, pos, t[1002], sum;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> k, pos=1, sum=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]<t[pos]) pos=i;
        }
        for (int i=1; i<=n; i++) if (i!=pos) {
            sum+=(k-t[i])/t[pos];
        }
        cout << sum << "\n";
    }
    return 0;
}