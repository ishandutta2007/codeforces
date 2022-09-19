#include <bits/stdc++.h>

using namespace std;
int n, m, s[100005];
vector<int> sz[100005];
long long e, k, h;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        int a=0, b=0, c=0;
        for (int j=0; j<sz[i].size(); j++) {
            int x=sz[i][j];
            if (s[x]==1) {
                a=1;
            }
            if (s[x]==2) {
                b=1;
            }
            if (s[x]==3) {
                c=1;
            }
        }
        if (!a) {
            s[i]=1;
            e++;
        } else if (!b) {
            s[i]=2;
            k++;
        } else if (!c) {
            s[i]=3;
            h++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    long long sum=e*(k+h)+k*h;
    if (sum!=m || !k || !h) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<sz[i].size(); j++) {
            int x=sz[i][j];
            if (s[i]==s[x]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << s[i] << " ";
    }
    return 0;
}