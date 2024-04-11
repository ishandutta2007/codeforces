#include <bits/stdc++.h>

using namespace std;
int w, n, si, pos, ert;
string s, sor, res, uj, uj2;
int main()
{
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();
        for (int i=n-1; i>=0; i--) {
            bool jo=0;
            for (int j=0; j<si; j++) {
                if (s[i]==sor[j]) {
                    jo=1;
                }
            }
            if (!jo) {
                sor+=s[i];
                si++;
            }
        }
        reverse(sor.begin(), sor.end());
        for (int i=0; i<n; i++) {
            for (int j=0; j<si; j++) {
                if (s[i]==sor[j]) {
                    ert+=j+1;
                }
            }
            if (ert==n) {
                pos=i+1;
            }
        }
        uj=s.substr(0, pos);
        if (pos) {
            for (int i=0; i<si; i++) {
                res+=uj;
                for (int j=0; j<uj.size(); j++) {
                    if (uj[j]!=sor[i]) {
                        uj2+=uj[j];
                    }
                }
                uj=uj2;
                uj2.clear();
            }
        }
        if (res==s) {
            cout << s.substr(0, pos) << " " << sor << "\n";
        } else {
            cout << -1 << "\n";
        }

        si=0, pos=0, ert=0;
        s.clear(), sor.clear(), res.clear(), uj.clear(), uj2.clear();
    }
    return 0;
}
/*
1
isi
*/