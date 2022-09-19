#include <bits/stdc++.h>

using namespace std;
int n, el=-1, ke=-1, si;
vector<pair<int, int> > sz;
vector<pair<int, string> > sol;
string s, p;
void add(int a) {p+=s[sz[a].second];}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s, n=s.size(), sz.push_back({-1, n});
    for (int i=n-1; i>=0; i--) {
        int x=s[i]-'a', y=sz.back().first, t=sz.back().second;
        if (x==y && i+1==t && (x>el || (x==el && x>ke))) sz.pop_back();
        else {
            if (x!=y && i+1==t && el!=y) ke=el, el=y;
            sz.push_back({x, i});
        }
        si=sz.size(), si--, p.clear();
        if (si>10) {
            for (int i=si; i>si-5; i--) add(i);
            p+="...";
            add(2), add(1);
        } else for (int i=si; i>=1; i--) add(i);
        sol.push_back({si, p});
    }
    for (int i=n-1; i>=0; i--) cout << sol[i].first << " " << sol[i].second << "\n";
    return 0;
}