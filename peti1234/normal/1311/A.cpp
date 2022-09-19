#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        int ans=0;
        if (a<b) {
            if ((b-a)%2==0) ans=2;
            else ans=1;
        }
        if (a>b) {
            if ((a-b)%2==0) ans=1;
            else ans=2;
        }
        cout << ans << "\n";
    }
    return 0;
}