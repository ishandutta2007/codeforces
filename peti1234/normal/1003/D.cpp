#include <bits/stdc++.h>

using namespace std;
int n, q;
map<int, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        m[-x]++;
    }
    for (int i=1; i<=q; i++) {
        int x;
        cin >> x;
        int ans=0;
        for (auto p:m) {
            int fi=-p.first, se=p.second;
            int db=min(se, x/fi);
            ans+=db, x-=db*fi;
        }
        cout << (x>0 ? -1 : ans) << "\n";
    }
    return 0;
}