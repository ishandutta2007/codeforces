#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x==max(y, z) || (x<y && y==z)) cout << "YES\n" << min(x, y) << " " << " " << min(x, z) << " " << min(y, z) << "\n";
        else cout << "NO\n";
    }
    return 0;
}