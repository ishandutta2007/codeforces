#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, maxi, cnt, db[c];
vector<pair<int, int> > sz;
vector<int> t[c];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, cnt=0, maxi=0, sz.clear(), sz.push_back({-1, 0});
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            sz.push_back({x, i});
        }
        sort(sz.begin(), sz.end());
        for (int i=1; i<=n; i++) {
            if (sz[i].first!=sz[i-1].first) cnt++, t[cnt].clear();
            t[cnt].push_back(sz[i].second);
        }
        for (int i=1; i<=cnt; i++) { int si=t[i].size(); maxi=max(maxi, si);}
        db[cnt]=t[cnt].size();
        for (int i=cnt-1; i>=1; i--) {
            int x=0, y=0,  a=t[i].size(), b=t[i+1].size(); db[i]=t[i].size();
            if (t[i][a-1]<t[i+1][0]) db[i]=db[i+1]+a;
            else for (int j=b-1; j>=0; j--) if (t[i][a-1]<t[i+1][j]) db[i]=a+b-j;
            for (int j=0; j<a; j++) if (t[i][j]<t[i+1][0]) maxi=max(maxi, db[i+1]+j+1);
            while(x<a) {
                while(y<b && t[i+1][y]<t[i][x]) y++;
                if (y==b) break;
                maxi=max(maxi, x+1+b-y), x++;
            }
            maxi=max(maxi, db[i]);
        }
        cout << n-maxi << "\n";
    }
    return 0;
}
/*
1 3 2 1 2
*/