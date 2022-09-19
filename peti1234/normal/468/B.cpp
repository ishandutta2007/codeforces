#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, a, b, t[c], ki[c];
bool fa[c], fb[c];
map<int, int> m;
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    return (ki[a]=holvan(ki[a]));
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        fa[b]|=fa[a], fb[b]|=fb[a];
        ki[a]=b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        m[t[i]]=i;
    }
    for (int i=1; i<=n; i++) {
        int x=m[a-t[i]], y=m[b-t[i]];
        if (x) {
            unio(i, x);
        } else {
            fb[holvan(i)]=1;
        }
        if (y) {
            unio(i, y);
        } else {
            fa[holvan(i)]=1;
        }
    }
    for (int i=1; i<=n; i++) {
        if (holvan(i)==i) {
            if (!fa[i] && !fb[i]) {
                fa[i]=1;
            }
            if (fa[i] && fb[i]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i=1; i<=n; i++) {
        cout << fb[holvan(i)] << " ";
    }
    return 0;
}