#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 125

using namespace std;

const int MAXN = 1000;

int l[MAXN + 1];
pair <int, int> r[MAXN + 1];

set <int> mst;

int sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, i, n;
    ios::sync_with_stdio(false);
    cin>> t;
    while(t > 0) {
        t--;
        cin >> n;
        for(i = 1; i <= n; i++) {
            cin >> l[i] >> r[i].first;
            r[i].first++;
            r[i].second = i;
        }
        sort(r + 1, r + n + 1);
        memset(sol, 0, sizeof(sol));
        mst.clear();
        int pos1 = 1, pos2 = 1;
        for(i = 1; i <= 5000; i++) {
            while(pos1 <= n && l[pos1] <= i) {
                mst.insert(pos1);
                pos1++;
            }
            while(pos2 <= n && r[pos2].first == i) {
                if(mst.find(r[pos2].second) != mst.end())
                    mst.erase(mst.find(r[pos2].second));
                pos2++;
            }
            if(mst.size() > 0) {
                sol[*mst.begin()] = i;
                mst.erase(mst.begin());
            }
        }
        for(i = 1; i <= n; i++) {
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}