#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, alap, maxi, db[c];
vector<pair<pair<int, int>, int> > sz;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        maxi=-1, alap=0;
        for (int i=1; i<=n; i++) {
            db[i]=0;
        }
        sz.clear();
        for (int i=1; i<=n; i++) {
            int l, r;
            cin >> l >> r;
            sz.push_back({{l, -1}, i});
            sz.push_back({{r, 1}, i});
        }
        sort(sz.begin(), sz.end());
        for (auto x:sz) {
            int p=x.first.second, id=x.second;
            if (p==-1) {
                s.insert(id);
            }
            if (p==1) {
                s.erase(id);
                if (s.size()==1) {
                    db[*s.begin()]++;
                }
                if (s.size()==0) {
                    db[id]--;
                    alap++;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            maxi=max(maxi, db[i]);
        }
        //cout << "valasz: ";
        cout << alap+maxi << "\n";
    }
    return 0;
}
/*
1
3
5 5
5 5
5 5
*/