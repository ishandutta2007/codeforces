#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();
        int kezd=n+1, veg=n+1;
        for (int i=0; i<n; i++) {
            if (s[i]!='a') {
                kezd=min(kezd, i);
                veg=n-i-1;
            }
        }
        if (kezd==n+1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if (kezd>=veg) {
                cout << 'a';
            }
            cout << s;
            if (kezd<veg) {
                cout << 'a';
            }
            cout << "\n";
        }
    }
    return 0;
}