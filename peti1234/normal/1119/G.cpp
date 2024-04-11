#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, m, mm, sum, t, tt, csop[c];
vector<pair<int, int> > sz;
vector<int> ans[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        sz.push_back({x, i});
        sum+=x;
    }
    while (sum%n) {
        sz[0].first++;
        sum++;
    }
    t=sum/n, tt=t, mm=m;
    for (int i=1; i<=t; i++) {
        ans[i].resize(m+1);
    }
    while (true) {
        sort(sz.rbegin(), sz.rend());
        while (t+1<m) {
            if (sz.size()==0 || sz[0].first>n) {
                break;
            }
            csop[m]=sz[m-1].first;
            for (int i=1; i<=t; i++) {
                ans[i][m]=sz[m-i].second;
                sz[m-i].first-=csop[m];
            }
            n-=csop[m];
            sz.pop_back();
            m--;
        }
        if (n==0 || sz.size()==0 || sz[0].first<n) {
            break;
        }
        for (int i=0; i<m; i++) {
            while (sz[i].first>=n) {
                sz[i].first-=n;
                for (int j=1; j<=m; j++) {
                    ans[t][j]=sz[i].second;
                }
                t--;
            }
        }
    }
    if (t==0) {
        csop[1]=n;
    }

    for (int i=1; i<=m; i++) {
        csop[i]=n-sz[i-1].first;
        int pos=0;
        for (int j=1; j<=m; j++) {
            if (i!=j) {
                pos++;
                ans[pos][i]=sz[j-1].second;
            }
        }
    }
    cout << tt << "\n";
    for (int i=1; i<=mm; i++) {
        cout << csop[i] << " ";
    }
    cout << "\n";
    for (int i=1; i<=tt; i++) {
        for (int j=1; j<=mm; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}