#include <bits/stdc++.h>
 
using namespace std;
int n, m;
vector<pair<int, int> >a;
vector<pair<int, int> >b;
int t[100001][2];
int x=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int c, d;
        cin >> c >> d;
        if (d==1) {
            a.push_back({c, i});
        } else {
            b.push_back({c, i});
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (b.size()>0 && a[0].first>b[0].first) {
        cout << -1;
        return 0;
    }
    t[a[0].second][0]=1;
    t[a[0].second][1]=2;
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<i; j++) {
            if (x==b.size()) {
                break;
            }
            int fi=b[x].first;
            int se=b[x].second;
            if (fi<a[i].first) {
                cout << -1;
                return 0;
            }
            t[se][0]=i+2;
            t[se][1]=j+1;
            x++;
        }
        if (i!=n-2) {
            int se=a[i+1].second;
            t[se][0]=i+2;
            t[se][1]=i+3;
        }
    }
    for (int i=1; i<=m; i++) {
        cout << t[i][0] << " " << t[i][1] << "\n";
    }
    return 0;
}