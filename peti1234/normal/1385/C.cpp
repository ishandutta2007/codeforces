#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, t[c], n, s, b, pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, b=0, s=c, pos=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=n; i>=1; i--) {
            if (t[i]>s) {pos=i; break;}
            b=max(b, t[i]);
            if (t[i]<b) s=t[i];
        }
        cout << pos << "\n";
    }
    return 0;
}