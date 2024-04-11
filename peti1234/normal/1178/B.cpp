#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long n, pref[c], suf[c], ans;
string s;
int main()
{
    cin >> s;
    n=s.size();
    for (int i=1; i<n; i++) {
        if (s[i]=='v' && s[i-1]=='v') {
            pref[i]++;
            suf[i]++;
        }
    }
    for (int i=2; i<n; i++) {
        pref[i]+=pref[i-1];
    }
    for (int i=n-2; i>=1; i--) {
        suf[i]+=suf[i+1];
    }
    for (int i=0; i<n; i++) {
        if (s[i]=='o') {
            ans+=pref[i]*suf[i];
        }
    }
    cout << ans << "\n";
    return 0;
}