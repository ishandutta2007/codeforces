#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n=0, kezd=0, veg=0, jo=1;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (jo && x) kezd++;
            if (x) veg++;
            if (!x) jo=0, veg=0;
        }
        cout << max(0, n+1-kezd-veg) << "\n";
    }
    return 0;
}