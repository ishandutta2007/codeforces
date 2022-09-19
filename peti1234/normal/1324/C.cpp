#include <bits/stdc++.h>

using namespace std;
int w, n, cnt, lh;
string s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> s, n=s.size(), cnt=0, lh=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='L') cnt++, lh=max(lh, cnt);
            else cnt=0;
        }
        lh=max(lh, cnt);
        cout << lh+1 << "\n";
    }
    return 0;
}