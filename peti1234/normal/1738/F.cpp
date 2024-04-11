#include <bits/stdc++.h>

using namespace std;


const int c=1005;
int n, t[c], cnt, ans[c];
vector<int> sz[c];
bool kesz[c], v[c];
int kerd(int a) {
    cout.flush() << "? " << a << endl;
    int x;
    cin >> x;
    sz[a].push_back(x), sz[x].push_back(a);
    return x;
}
void dfs(int a) {
    v[a]=true;
    ans[a]=cnt;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    while (true) {
        int pos=0;
        for (int i=1; i<=n; i++) {
            if (!kesz[i] && (pos==0 || t[i]>t[pos])) {
                pos=i;
            }
        }
        kesz[pos]=1;
        for (int i=1; i<=t[pos]; i++) {
            int x=kerd(pos);
            if (kesz[x]) {
                break;
            }
            kesz[x]=1;
        }
        if (!pos) {
            break;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << "! ";
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    cnt=0;
    for (int i=1; i<=n; i++) {
        t[i]=0, kesz[i]=0, v[i]=0, ans[i]=0, sz[i].clear();
    }
}
int main()
{

    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
5
1 2 3 2 1
*/