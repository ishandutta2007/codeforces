#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, ki[c], si[c], pos;
vector<int> sz[c];
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
bool unio(int a, int b) {
    int sa=a, sb=b;
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
        cout << sa << " " << sb << "\n";
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        si[a]++, si[b]++;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (si[i]>si[pos]) {
            pos=i;
        }
    }
    for (auto x:sz[pos]) {
        unio(pos, x);
    }
    for (int i=1; i<=n; i++) {
        for (auto x:sz[i]) {
            unio(x, i);
        }
    }
    return 0;
}