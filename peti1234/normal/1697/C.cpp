#include <bits/stdc++.h>

using namespace std;
int w;
bool jo(string a, string b) {
    if (a.size()!=b.size()) return 0;
    int cnt=0;
    for (int i=0; i<a.size(); i++) {
        if (a[i]<b[i]) cnt++;
        if (b[i]<a[i]) cnt--;
        if (cnt<0) return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        string s[2], ab[2], bc[2], ac[2];
        for (int i=0; i<2; i++) {
            cin >> s[i];
            for (int j=0; j<n; j++) {
                if (s[i][j]=='a') ab[i]+="a", ac[i]+="a";
                if (s[i][j]=='b') ab[i]+="b", bc[i]+="b";
                if (s[i][j]=='c') ac[i]+="c", bc[i]+="c";
            }
        }
        cout << (jo(ab[0], ab[1]) && jo(bc[0], bc[1]) && ac[0]==ac[1] ? "YES" : "NO") << "\n";
    }
    return 0;
}