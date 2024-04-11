#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, cnt, f, ki[c], si[c], pos;
vector<int> sz[c], spec;
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
bool unio(int a, int b) {
    int sa=a, sb=b;
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
        //cout << sa << " " << sb << "\n";
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> cnt;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        if (a!=1 && b!=1) {
            unio(a, b);
        }
        si[a]++, si[b]++;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (auto x:sz[1]) {
        if (unio(1, x)) {
            spec.push_back(x);
            f++;
        }
    }
    if (si[1]<cnt || f>cnt) {
        cout << "NO\n";
        return 0;
    }
    for (int i=1; i<=n; i++) {
        ki[i]=0;
    }
    cout << "YES\n";
    for (auto x:spec) {
        if (unio(1, x)) {
            cout << 1 << " " << x << "\n";
        }
    }
    for (auto x:sz[1]) {
        if (f<cnt && unio(1, x)) {
            f++;
            cout << 1 << " " << x << "\n";
        }
    }
    for (int i=2; i<=n; i++) {
        for (auto x:sz[i]) {
            if (x!=1 && unio(i, x)) {
                cout << i << " " << x << "\n";
            }
        }
    }
    return 0;
}