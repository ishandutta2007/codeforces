#include <bits/stdc++.h>

using namespace std;
string s;
vector<pair<int, int> > sz;
int main()
{
    cin >> s;
    int el=0;
    int db=0;
    for (int i=0; i<s.size(); i++) {
        int c=s[i]-'A'+1;
        if (c!=el) {
            if (el!=0) {
                sz.push_back({el, db});
            }
            el=c, db=1;
        } else {
            db++;
        }
    }
    sz.push_back({el, db});
    int k=0, v=sz.size();
    v--;
    while(k<v) {
        if (sz[k].first==sz[v].first && sz[k].second+sz[v].second>=3) {
            k++, v--;
        } else {
            cout << 0 << "\n";
            return 0;
        }
    }
    if (sz[k].second>=2) {
        cout << sz[k].second+1 << "\n";
    } else {
        cout << 0 << "\n";
    }
    return 0;
}