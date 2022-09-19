#include <bits/stdc++.h>

using namespace std;
int w, n;
vector<int> sz;
char ans[205][205];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                ans[i][j]=(i==j ? 'X' : '=');
            }
        }
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            if (c=='2') {
                sz.push_back(i);
            }
        }
        int si=sz.size();
        if (si==1 || si==2) {
            cout << "NO\n";
        } else {
            if (si>2) {
                for (int i=0; i<si; i++) {
                    int a=sz[i], b=sz[(i+1)%si];
                    ans[a][b]='+', ans[b][a]='-';
                }
            }

            cout << "YES\n";
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    cout << ans[i][j];
                }
                cout << "\n";
            }
        }

        sz.clear();
    }
    return 0;
}