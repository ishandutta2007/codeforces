#include <bits/stdc++.h>

using namespace std;
int w, n, baj;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        baj=0;
        n=s.size();
        for (int i=0; i<n; i++) {
            if (s[i]=='?') {
                char el='.', kov='.', ert='a';
                if (i>0) {
                    el=s[i-1];
                }
                if (i<n-1) {
                    kov=s[i+1];
                }
                while (ert==el || ert==kov) {
                    ert++;
                }
                s[i]=ert;
            }
            if (i>0 && s[i]==s[i-1]) {
                baj=1;
            }
        }
        if (baj) {
            cout << -1 << "\n";
        } else {
            cout << s << "\n";
        }
    }
    return 0;
}