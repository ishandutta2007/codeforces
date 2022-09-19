#include <bits/stdc++.h>

using namespace std;
map<int, pair<int, int> > m;
int main()
{
    ios_base::sync_with_stdio(false);
    int k;
    cin >> k;
    for (int j=1; j<=k; j++) {
        int n, sum=0;
        map<int, int> m2;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sum+=x;
            m2[x]=i;
        }
        for (auto x:m2) {
            int d=sum-x.first;
            if (m.find(d)!=m.end()) {
                cout << "YES\n" << m[d].first << " " << m[d].second << "\n" << j << " " << x.second << "\n";
                return 0;
            }
            m[d]={j, x.second};
        }
    }
    cout << "NO\n";
    return 0;
}