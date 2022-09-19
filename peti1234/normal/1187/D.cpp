#include <bits/stdc++.h>
 
using namespace std;
int q;
vector <pair<int, int> > a;
vector <pair<int, int> > b;
int ida[300001][2];
int idb[300001];
int elotta[300001];
int mna[300001];
int elottb[300001];
int mnb[300001];
bool aert(int s, int f)
{
    if (s==f) {
        return true;
    }
    int t=(s+f)/2;
    vector<pair<int, int> > q;
    for (int i=s; i<=t; i++) {
        q.push_back({ida[i][0], ida[i][1]});
    }
    sort(q.begin(), q.end());
    for (int i=1; i<q.size(); i++) {
        q[i].second=max(q[i].second, q[i-1].second);
    }
    for (int i=t+1; i<=f; i++) {
        int x=-1, y=q.size();
        while(y-x>1) {
            int z=(x+y)/2;
            if (ida[i][0]>=q[z].first) {
                x=z;
            } else {
                y=z;
            }
        }
        if (x!=-1 && ida[i][1]<q[x].second) {
            return false;
        }
    }
    if (!aert(s, t)) {
        return false;
    }
    return aert(t+1, f);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i=1; i<=q; i++) {
        a.clear();
        b.clear();
        int n;
        cin >> n;
        a.push_back({0, 0});
        b.push_back({0, 0});
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            a.push_back({x, i});
        }
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            b.push_back({x, i});
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i=1; i<=n; i++) {
            ida[a[i].second][0]=i;
            idb[b[i].second]=i;
        }
        for (int i=1; i<=n; i++) {
            elottb[idb[i]]=i;
        }
        for (int i=1; i<=n; i++) {
            ida[i][1]=elottb[ida[i][0]];
        }
        bool ans=true;
        ans=aert(1, n);
        for (int i=1; i<=n; i++) {
            if (a[i].first!=b[i].first) {
                ans=false;
            }
        }
        if (ans) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}