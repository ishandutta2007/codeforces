#include <bits/stdc++.h>

using namespace std;
vector<int> a, b;
vector<int> c;
int n, m, mini=INT_MAX;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<n; i++) {int x; cin >> x; a.push_back(x);}
    for (int i=0; i<n; i++) {int x; cin >> x; b.push_back(x);}
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i=0; i<n; i++) {
        int x=(b[i]+m-a[0])%m;
        c.clear();
        for (int i=0; i<n; i++) {
            c.push_back((a[i]+x)%m);
        }
        sort(c.begin(), c.end());
        for (int i=0; i<c.size(); i++) {
            if (c[i]!=b[i]) {
                break;
            }
            if (i==n-1) mini=min(mini, x);
        }
    }
    cout << mini << "\n";
    return 0;
}
/*
3 8
1 2 5
2 6 7
*/