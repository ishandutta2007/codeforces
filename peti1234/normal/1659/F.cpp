#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, db[c], pos, p[c], kezd, spec, par;
bool v[c];
void dfs(int a) {
    v[a]=true;
    if (!v[p[a]]) {
        dfs(p[a]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> kezd;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            db[a]++, db[b]++;
        }
        for (int i=1; i<=n; i++) {
            if (db[i]>=2) {
                pos=i;
            }
        }

        for (int i=1; i<=n; i++) {
            cin >> p[i];
            if (p[i]!=i) {
                spec++;
            }
        }
        par=n;
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                par--;
                dfs(i);
            }
        }
        if (kezd==pos) {
            par++;
        }
        if (db[pos]<n-1 || spec==0 || spec==2 && p[kezd]==kezd || par%2==0 && (p[pos]==pos || kezd!=pos && p[pos]!=kezd)) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }

        for (int i=1; i<=n; i++) {
            db[i]=0, p[i]=0, v[i]=0;
        }
        pos=0, kezd=0, spec=0, par=0;
    }
    return 0;
}
/*
1
4 1
1 2 1 3 1 4
1 3 4 2
*/