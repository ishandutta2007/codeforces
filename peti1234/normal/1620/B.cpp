#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long h, w, maxi=0;
        cin >> h >> w;
        for (int i=0; i<4; i++) {
            int db;
            cin >> db;
            long long kis=0, nagy=0;
            cin >> kis;
            for (int j=1; j<db; j++) {
                cin >> nagy;
            }
            maxi=max(maxi, (nagy-kis)*(i<2 ? w : h));
        }
        cout << maxi << "\n";
    }
    return 0;
}