#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, db[c], ut[c];
bool v[c];
string t[c];
map<pair<int, int>, int> m;
map<int, int> m2;
vector<pair<int, int> > p, p2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        for (auto c:t[i]) {
            int ert=0;
            if (c=='a') ert=1;
            if (c=='e') ert=2;
            if (c=='i') ert=3;
            if (c=='o') ert=4;
            if (c=='u') ert=5;
            if (ert) {
                db[i]++;
                ut[i]=ert;
            }
        }
        pair<int, int> s={db[i], ut[i]};
        if (m.find(s)!=m.end()) {
            p.push_back({m[s], i});
            v[m[s]]=1, v[i]=1;
            m.erase(s);
        } else {
            m[s]=i;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            int s=db[i];
            if (m2.find(s)!=m2.end()) {
                p2.push_back({m2[s], i});
                m2.erase(s);
            } else {
                m2[s]=i;
            }
        }
    }
    int si=p.size(), si2=p2.size();
    while (si>si2) {
        p2.push_back(p.back());
        p.pop_back();
        si--, si2++;
    }
    cout << si << "\n";
    while (p.size()>0) {
        cout << t[p2.back().first] << " " << t[p.back().first] << "\n" << t[p2.back().second] << " " << t[p.back().second] << "\n";
        p.pop_back(), p2.pop_back();
    }
    return 0;
}