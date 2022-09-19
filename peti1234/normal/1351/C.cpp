#include <bits/stdc++.h>

using namespace std;
int w, n, a, b, db;
vector<pair<int, int> > ns, ew;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> s, n=s.size(), a=0, b=0, db=0, ns.clear(), ew.clear();
        for (int i=0; i<n; i++) {
            if (s[i]=='N') ns.push_back({a, b}), a++;
            if (s[i]=='S') ns.push_back({a-1, b}), a--;
            if (s[i]=='E') ew.push_back({a, b}), b++;
            if (s[i]=='W') ew.push_back({a, b-1}), b--;
        }
        sort(ns.begin(), ns.end()), sort(ew.begin(), ew.end());
        for (int i=1; i<ns.size(); i++) if (ns[i].first==ns[i-1].first && ns[i].second==ns[i-1].second) db++;
        for (int i=1; i<ew.size(); i++) if (ew[i].first==ew[i-1].first && ew[i].second== ew[i-1].second) db++;
        cout << n*5-db*4 << "\n";
    }
    return 0;
}