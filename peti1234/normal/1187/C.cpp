#include <bits/stdc++.h>
 
using namespace std;
bool v[1001];
vector<pair<int, int> > r;
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a==0) {
            r.push_back({b, c});
        } else {
            for (int i=b+1; i<=c; i++) {
                v[i]=true;
            }
        }
    }
    for (int i=0; i<r.size(); i++) {
        int fi=r[i].first;
        int se=r[i].second;
        bool a=true;
        for (int i=fi+1; i<=se; i++) {
            if (!v[i]) {
                a=false;
            }
        }
        if (a) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    int a=2000;
    cout << a << " ";
    for (int i=2; i<=n; i++) {
        if (!v[i]) {
            a--;
        }
        cout << a << " ";
    }
    return 0;
}