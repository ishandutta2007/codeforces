#include <bits/stdc++.h>

using namespace std;
int w, n, el;
bool a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, el=0, a=0, b=0, c=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x<el) c=1;
            el=x;
        }
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x) b=1;
            else a=1;
        }
        if ((a && b) || !c) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}