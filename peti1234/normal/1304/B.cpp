#include <bits/stdc++.h>

using namespace std;
int n, m, db;
bool jo;
string s, pal;
set<string> k;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        string p, fp;
        cin >> p, fp=p;
        reverse(fp.begin(), fp.end());
        if (k.find(fp)!=k.end()) {
            s+=p;
            db+=2;
        }
        if (p==fp) {
            pal=p;
            jo=1;
        }
        k.insert(p);
    }
    cout << (db+jo)*m << "\n";
    cout << s << pal;
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return 0;
}