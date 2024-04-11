#include <bits/stdc++.h>

using namespace std;
int w, n, m;
bool v[300002];
vector<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m;
        q.clear();
        for (int i=1; i<=3*n; i++) {
            v[i]=false;
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            if (!v[a] && !v[b]) {
                v[a]=1, v[b]=1;
                q.push_back(i);
            }
        }
        if (q.size()>=n) {
            cout << "Matching" << "\n";
            for (int i=0; i<n; i++) {
                cout << q[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "IndSet" << "\n";
            int db=0;
            for (int i=1; i<=3*n; i++) {
                if (!v[i] && db<n) {
                    cout << i << " ";
                    db++;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}