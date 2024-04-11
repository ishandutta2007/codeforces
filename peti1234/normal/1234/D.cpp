#include <bits/stdc++.h>

using namespace std;
string s;
int n, q;
set<int> p[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    n=s.size();
    for (int i=1; i<=n; i++) {
        int ert=s[i-1]-'a';
        p[ert].insert(i);
    }
    cin >> q;
    for (int i=1; i<=q; i++) {
        int id;
        cin >> id;
        if (id==1) {
            int pos;
            char c;
            cin >> pos >> c;
            int regi=s[pos-1]-'a', uj=c-'a';
            p[regi].erase(pos);
            p[uj].insert(pos);
            s[pos-1]=c;
        } else {
            int l, r;
            cin >> l >> r;
            int cnt=0;
            for (int i=0; i<26; i++) {
                auto lb=p[i].lower_bound(l);
                if (lb!=p[i].end() && *lb<=r) {
                    cnt++;
                }
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}