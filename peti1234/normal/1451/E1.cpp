#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, ans[c], jo;
vector<int> sz[c];
int main()
{
    cin >> n;
    sz[0].push_back(1);
    for (int i=2; i<=n; i++) {
        cout.flush() << "XOR " << 1 << " " << i << "\n";
        cin >> ans[i];
        sz[ans[i]/2].push_back(i);
    }
    for (int i=0; i<n; i++) {
        if (sz[i].size()>1) {
            int a=sz[i][0], b=sz[i][1];
            cout.flush() << "AND " << a << " " << b << "\n";
            if (ans[a]==ans[b]) jo=1;
            int xo; cin >> xo;
            xo^=ans[a];
            for (int i=1; i<=n; i++) {
                ans[i]^=xo;
            }
            break;
        }
    }
    /*
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    */
    //cout.flush() << "\n";
    if (!jo) {
        bool k=0;
        for (int i=2; i<=n; i++) {
            if (ans[1]%2==ans[i]%2) {
                cout.flush() << "AND " << 1 << " " << i << "\n";
                int xo; cin >> xo;
                xo^=ans[1];
                xo%=2;
                for (int i=1; i<=n; i++) {
                    ans[i]^=xo;
                }
                k=1;
                break;
            }
        }
        if (!k) {
            cout.flush() << "AND " << 2 << " " << 3 << "\n";
            int xo; cin >> xo;
            xo^=ans[2];
            xo%=2;
            for (int i=1; i<=n; i++) {
                ans[i]^=xo;
            }
        }
    }
    cout << "! ";
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}