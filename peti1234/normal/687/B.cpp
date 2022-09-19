#include <bits/stdc++.h>

using namespace std;
int a, n;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> a;
    for (int i=2; i<=a; i++) {
        int ert=1;
        while(a%i==0) {
            a/=i, ert*=i;
        }
        if (ert>1) {
            sz.push_back(ert);
        }
    }
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        for (int j=0; j<sz.size(); j++) {
            if (x%sz[j]==0) sz[j]=1;
        }
    }
    for (int j:sz) {
        if (j!=1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}