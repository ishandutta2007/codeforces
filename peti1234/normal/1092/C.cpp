#include <bits/stdc++.h>

using namespace std;
int n;
string s[205], a, b;
void ch(string p) {
    set<pair<string, bool> > m;
    for (int i=1; i<n; i++) {
        m.insert({p.substr(0, i), 0});
        m.insert({p.substr(n-i, i), 1});
    }
    string ans;
    for (int i=1; i<=2*n-2; i++) {
        if (m.find({s[i], 0})!=m.end()) {
            ans+="P";
            m.erase({s[i], 0});
        } else if (m.find({s[i], 1})!=m.end()) {
            ans+="S";
            m.erase({s[i], 1});
        } else {
            return;
        }
    }
    cout << ans << "\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=2*n-2; i++) {
        string p;
        cin >> p;
        if (p.size()==n-1) {
            if (a.size()==0) a=p;
            else b=p;
        }
        s[i]=p;
    }
    ch(a+b[n-2]), ch(b+a[n-2]);
    return 0;
}