#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, m, k, kov[c], el[c], ki[c], s, cnt;
bool v[c], baj, jo;
set<int> sz[c];
queue<int> q;
void add(int a) {
    q.push(a);
    v[a]=true, kov[el[a]]=kov[a], el[kov[a]]=el[a];
}
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    return ki[a]=holvan(ki[a]);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    ki[a]=b;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        el[i]=i-1, kov[i]=i+1;
    }
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        s+=(min(a, b)==1);
        sz[a].insert(b), sz[b].insert(a);
    }
    for (int i=2; i<=n; i++) {
        if (!v[i]) {
            jo=0, cnt++;
            add(i);
            while (q.size()>0) {
                int a=q.front(); q.pop();
                for (int i=1; i<=n; i=kov[i]) {
                    if (sz[a].find(i)==sz[a].end()) {
                        if (i==1) {
                            jo=1;
                        } else {
                            unio(a, i);
                            add(i);
                        }
                    }
                }
            }
            if (!jo) {
                baj=1;
            }
        }
    }
    if (cnt>k || baj || s+k>=n) {
        cout << "impossible\n";
    } else {
        cout << "possible\n";
    }
    return 0;
}