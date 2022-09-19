#include <bits/stdc++.h>
 
using namespace std;
string s, k, p;
int t[31];
int q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> s >> k >> p;
        for (int i=0; i<30; i++) {
            t[i]=0;
        }
        for (int i=0; i<s.size(); i++) {
            int x=s[i]-'a';
            t[x]++;
        }
        for (int i=0; i<k.size(); i++) {
            int x=k[i]-'a';
            t[x]--;
        }
        for (int i=0; i<p.size(); i++) {
            int x=p[i]-'a';
            t[x]++;
        }
        bool v=true;
        int x=0, y=0;
        while (x<s.size()) {
            if (y>=k.size()) {
                v=false;
                break;
            }
            if (s[x]==k[y]) {
                x++;
            }
            y++;
        }
        for (int i=0; i<30; i++) {
            if (t[i]<0) {
                v=false;
            }
        }
        if (!v) {
            cout << "NO";
        } else {
            cout << "YES";
        }
        cout << "\n";
    }
    return 0;
}