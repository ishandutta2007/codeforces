#include <bits/stdc++.h>

using namespace std;
int w, n, maxi, cnt;
string s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> s;
        maxi=0, cnt=0;
        for (int i=n-1; i>=0; i--) {
            if (s[i]=='A') {
                maxi=max(maxi, cnt);
                cnt=0;
            } else {
                cnt++;
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}