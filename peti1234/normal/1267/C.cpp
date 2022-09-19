#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int n, db[c], omax, maxi, sa;
vector<int> sz[c];
vector<pair<int, int> > ans;
void valt(int a) {
    db[a]--, db[a-1]++;
    int ert=sz[a].back();
    sz[a].pop_back(), sz[a-1].push_back(ert);
}
void add(int a, int b) {
    int s=sz[a].back();
    valt(a);
    ans.push_back({s, sz[b].back()});
    valt(b);
    sa++;
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        db[x]++;
        sz[x].push_back(i);
    }
    while (true) {
        maxi=0, omax=0;
        for (int i=1; i<=n; i++) {
            if (db[i]) {
                maxi=i;
                if (i%2) {
                    omax=i;
                }
            }
        }
        if (db[1]) {
            if (omax>1) {
                add(1, omax);
            } else {
                if (db[1]==1 && maxi==1) {
                    cout << -1 << "\n";
                    return 0;
                }
                add(1, maxi);
            }
        } else if (db[2]>=2) {
            if (maxi>2) {
                int kov=maxi-1;
                add(2, 2), add(1, maxi), add(1, kov);
            } else {
                if (db[2]==2) {
                    cout << -1 << "\n";
                    return 0;
                }
                add(2, 2);
            }
        } else {
            break;
        }
    }
    if (maxi || sa<n-1) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << 2 << " " << x.first << " " << x.second << "\n";
    }
    return 0;
}