#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> t[1001];
vector<pair<int, pair<int, int> > > sz;
vector<int> bka[1001];
bool miaf[1001];
int kov=1;
bool v[1001];
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        if (b!=n) {
            cout << "NO" << endl;
            return 0;
        } else {
            t[a].push_back(i);
        }
    }
    for (int i=1; i<n; i++) {
        int s=t[i].size();
        if (s==0) {
            continue;
        }
        v[i]=true;
        while(v[kov]) {
            kov++;
        }
        if (s==1) {
            sz.push_back({t[i][0], {i, n}});
        }
        else {
        int x=i;
        for (int j=0; j<s-1; j++) {
            sz.push_back({t[i][j], {x, kov}});
            v[kov]=true;
            x=kov;
            if (kov>i) {
                cout << "NO" << endl;
                return 0;
            }
            while(v[kov]) {
                kov++;
            }
        }
        sz.push_back({t[i][s-1], {x, n}});
        }
    }
    cout << "YES" << endl;
    sort(sz.begin(), sz.end());
    for (int i=0; i<n-1; i++) {
        cout << sz[i].second.first << " " << sz[i].second.second << endl;
    }

    return 0;
}