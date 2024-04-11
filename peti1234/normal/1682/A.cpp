#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int koz=n/2, cnt=0;
        for (int i=koz; i<n; i++) {
            if (s[i]==s[koz]) cnt++;
            else break;
        }
        cout << 2*cnt-n%2 << "\n";
    }
    return 0;
}