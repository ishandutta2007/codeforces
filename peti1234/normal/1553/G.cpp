#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, t[c], q, ki[c];
vector<int> oszt[c];
set<int> s[c];
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=2; i<c; i++) {
        if (oszt[i].size()==0) {
            for (int j=i; j<c; j+=i) {
                oszt[j].push_back(i);
            }
        }
    }
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        for (auto x:oszt[t[i]]) {
            unio(t[i], x);
        }
    }
    for (int i=1; i<=n; i++) {
        for (auto x:oszt[t[i]+1]) {
            s[holvan(t[i])].insert(holvan(x));
            for (auto y:oszt[t[i]+1]) {
                s[holvan(x)].insert(holvan(y));
            }
        }
    }
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        a=holvan(t[a]), b=holvan(t[b]);
        if (a==b) {
            cout << 0 << "\n";
        } else if (s[a].find(b)!=s[a].end() || s[b].find(a)!=s[b].end()) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
    return 0;
}