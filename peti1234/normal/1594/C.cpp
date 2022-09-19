#include <bits/stdc++.h>

using namespace std;
int w, n;
char c;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> c >> s;
        int jo=1, pos=0;
        for (int i=0; i<n; i++) {
            if (s[i]!=c) {
                jo=0;
            }
            if (2*(i+1)>n && s[i]==c) {
                pos=i+1;
            }
        }
        if (jo) {
            cout << 0 << "\n";
        } else {
            if (!pos) {
                cout << 2 << "\n" << n-1 << " " << n << "\n";
            } else {
                cout << 1 << "\n" << pos << "\n";
            }
        }
    }
    return 0;
}