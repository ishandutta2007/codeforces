#include <bits/stdc++.h>

using namespace std;
int n, m;
int a, b, c;
int t[300001];
vector<int> sz[300001];
bool v[300001];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
    }
    v[t[n]]=true;
    b=1;
    for (int i=n-1; i>=1; i--) {
        for (int j=0; j<sz[t[i]].size(); j++) {
            int x=sz[t[i]][j];
            if (v[x]) {
                a++;
            }
        }
        if (a==b) {
            c++;
        } else {
            v[t[i]]=true;
            b++;
        }
        a=0;
    }
    cout << c << endl;
    return 0;
}