#include <bits/stdc++.h>

using namespace std;
const int c=2000002;
int n, kov[c], pos=1, pos2;
bool v[c];
vector<int> sz[2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        kov[i]=i+x;
    }
    for (int i=n+1; i<=2*n; i++) {
        int x;
        cin >> x;
        kov[i]=i-x;
    }
    while (!v[pos]) {
        v[pos]=1;
        pos=kov[pos];
    }
    pos2=pos;
    do {
        if (pos<=n) {
            sz[0].push_back(pos);
        } else {
            sz[1].push_back(pos-n);
        }
        pos=kov[pos];
    } while (pos!=pos2);
    for (int i=0; i<2; i++) {
        cout << sz[i].size() << "\n";
        for (auto x:sz[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}