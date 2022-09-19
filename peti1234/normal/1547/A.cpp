#include <bits/stdc++.h>

using namespace std;
int w, xa, ya, xb, yb, xc, yc, ans;
bool koz(int a, int b, int c) {
    return (c>=min(a, b) && c<=max(a, b));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        ans=abs(xa-xb)+abs(ya-yb);
        if (xa==xb && xb==xc && koz(ya, yb, yc) || (ya==yb && yb==yc && koz(xa, xb, xc))) {
            ans+=2;
        }
        cout << ans << "\n";
    }
    return 0;
}