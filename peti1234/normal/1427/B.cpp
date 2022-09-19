#include <bits/stdc++.h>

using namespace std;
int w, n, k, db, st, el, ert;
vector<int> sz;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, sz.clear(), db=0, el=-2, ert=0;
        cin >> s;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='W') {
                db++, ert++;
                if (el+1==i) ert++;
                if (db!=1 && el+1!=i) sz.push_back(i-el-1);
                el=i;
            }
        }
        k=min(k, n-db);
        sort(sz.begin(), sz.end());
        if (db==0) {
            cout << max(0, 2*k-1) << "\n";
        } else {
            for (int i=0; i<sz.size(); i++) {
                if (k>=sz[i]) {
                    ert+=2*sz[i]+1;
                    k-=sz[i];
                } else {
                    ert+=2*k;
                    k=0;
                }
            }
            cout << ert+2*k << "\n";
        }
    }
    return 0;
}