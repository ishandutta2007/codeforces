#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> q;
vector<pair<int, int> > a;
vector<pair<int, int> > b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<n; i++) {
        if (n%i==0) {
            q.push_back(i);
        }
    }
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        x%=n;
        y%=n;
        if (x>y) {
            swap(x, y);
        }
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    for (int i=0; i<q.size(); i++) {
        int z=q[i];
        b.clear();
        for (int i=0; i<m; i++) {
            int x=a[i].first;
            int y=a[i].second;
            x+=z;
            y+=z;
            x%=n;
            y%=n;
            if (x>y) {
                swap(x, y);
            }
            b.push_back({x, y});
        }
        sort(b.begin(), b.end());
        bool c=true;
        for (int i=0; i<a.size(); i++) {
            if (a[i].first!=b[i].first) {
                c=false;
            }
            if (a[i].second!=b[i].second) {
                c=false;
            }
        }
        if (c) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}