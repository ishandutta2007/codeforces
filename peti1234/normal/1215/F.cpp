#include <bits/stdc++.h>

using namespace std;
const int c=2000005;
int p1, n, len, p2, f, l[c], r[c];

vector<int> sz[c], fr;
bool v[c];
int kezd;
vector<int> ans;
int lsb(int a) {
    return (a & -a);
}
void dfs(int a) {
    v[a]=true;
    fr.push_back(a);
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> p1 >> n >> len >> p2;
    f=n+len;
    for (int i=1; i<=p1; i++) {
        int a, b;
        cin >> a >> b;
        sz[a+f].push_back(b);
        sz[b+f].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        cin >> l[i] >> r[i];
        int s=l[i]-1;
        while (s) {
            //cout << "kulon " << i << " " << s+n << "\n";
            sz[i].push_back(s+n+f);
            sz[s+n].push_back(i+f);
            s-=lsb(s);
        }
        s=r[i];
        while (s<=len) {
            //cout << "egyutt " << i << " " << s+n << "\n";
            sz[i].push_back(s+n);
            sz[s+n+f].push_back(i+f);
            s+=lsb(s);
        }
    }
    for (int i=1; i<=p2; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b+f);
        sz[b].push_back(a+f);
    }

    /*for (int i=1; i<=2*f; i++) {
        cout << "elek " << i << ": ";
        for (auto x:sz[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }*/
    for (int i=1; i<=f; i++) {
        if (!v[i] && !v[i+f]) {
            dfs(i);
            if (v[i+f]) {
                for (auto x:fr) {
                    v[x]=0;
                }
                fr.clear();
                dfs(i+f);
                if (v[i]) {
                    cout << -1 << "\n";
                    return 0;
                }
            }
            fr.clear();
        }
    }

    for (int i=1; i<=n; i++) {
        if (v[i]) {
            ans.push_back(i);
            kezd=max(kezd, l[i]);
        }
    }
    cout << ans.size() << " " << kezd << "\n";
    for (auto x:ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
/*
0 2 4 0
1 2
3 4
*/