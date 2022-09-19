#include <bits/stdc++.h>

using namespace std;
int w, a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b >> c;
        if (!a && !b) for (int i=1; i<=c+1; i++) cout << 1;
        else {
            for (int i=1; i<=a+1; i++) cout << 0;
            if (b) cout << 1, b--;
            for (int i=1; i<=c; i++) cout << 1;
            for (int i=0; i<b; i++) cout << i%2;
        }
        cout << endl;
    }
    return 0;
}