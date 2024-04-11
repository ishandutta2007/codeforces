#include <bits/stdc++.h>
 
using namespace std;
bool v[101][101];
int dist[101][101];
int n;
vector<int> q;
int p;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char c;
            cin >> c;
            if (c=='1') {
                dist[i][j]=true;
            }
        }
    }
    cin >> p;
    for (int i=1; i<=p; i++) {
        int x;
        cin >> x;
        q.push_back(x);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i!=j && !dist[i][j]) {
                dist[i][j]=101;
            }
        }
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    ans.push_back(q[0]);
    for (int i=0; i<p; i++) {
        for (int j=1; j<101; j++) {
            if (i+j==p || dist[q[i]][q[i+j]]!=j) {
                ans.push_back(q[i+j-1]);
                if (i+j==p) {
                    i=10000000;
                }
                i+=j-2;
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}