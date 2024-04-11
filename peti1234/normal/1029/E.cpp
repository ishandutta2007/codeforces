#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, cnt;
vector<int> sz[c];
bool jo[c], v[c];
void add(int a) {
    jo[a]=1;
    for (auto x:sz[a]) {
        jo[x]=1;
    }
}
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            if (!jo[x]) {
                cnt++;
                add(a);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    add(1);
    for (auto x:sz[1]) {
        add(x);
    }
    dfs(1);
    cout << cnt << "\n";
    return 0;
}