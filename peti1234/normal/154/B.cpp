#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, act[c];
bool pr[c], v[c];
vector<int> sz[c];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i=2; i<=n; i++) {
        if (!pr[i]) {
            for (int j=i; j<=n; j+=i) {
                pr[j]=1;
                sz[j].push_back(i);
            }
        }
    }
    for (int i=1; i<=m; i++) {
        char c; int x;
        cin >> c >> x;
        if (c=='+') {
            if (v[x]) {
                cout << "Already on";
            }
            else {
                int pr=0;
                for (int j:sz[x]) {
                    if (act[j]) pr=act[j];
                }
                if (pr) {
                    cout << "Conflict with " << pr;
                } else {
                    cout << "Success";
                    v[x]=1;
                    for (int j:sz[x]) {
                        act[j]=x;
                    }
                }
            }
        } else {
            if (!v[x]) {
                cout << "Already off";
            }
            else {
                cout << "Success";
                v[x]=0;
                for (int j:sz[x]) {
                    act[j]=0;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}