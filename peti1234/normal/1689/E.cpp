#include <bits/stdc++.h>

using namespace std;
const int c=2005, k=31;
int w, n, t[c], db[k][k], ans;
bool kesz, v[k];
void dfs(int a) {
    v[a]=true;
    for (int i=0; i<k; i++) {
        if (db[a][i] && !v[i]) {
            dfs(i);
        }
    }
}
void check() {
    if (kesz) {
        return;
    }
    int comp=0;
    for (int i=1; i<=n; i++) {
        if (t[i]==0) {
            comp+=2;
        }
    }
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++) {
            if (db[i][j] && !v[i]) {
                dfs(i);
                comp++;
            }
        }
    }
    if (comp==1) {
        //cout << "megoldas:\n";
        cout << ans << "\n";
        for (int i=1; i<=n; i++) {
            cout << t[i] << " ";
        }
        cout << "\n";
        kesz=1;
    }

    for (int i=0; i<k; i++) {
        v[i]=0;
    }
}
void add(int x, int s) {
    if (kesz) {
        return;
    }
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++) {
            if ((x & (1<<i)) && (x & (1<<j))) {
                db[i][j]+=s;
            }
        }
    }
}
void try1() {
    for (int i=1; i<=n; i++) {
        add(t[i], -1),
        t[i]--;
        add(t[i], 1);
        check();
        add(t[i], -1);
        t[i]+=2;
        add(t[i], 1);
        check();
        add(t[i], -1);
        t[i]--;
        add(t[i], 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]==0) {
                t[i]++, ans++;
            }
            add(t[i], 1);
        }
        check();
        ans++;
        try1();
        int pos=1;
        for (int i=1; i<=n; i++) {
            if (__builtin_ctz(t[i])>__builtin_ctz(t[pos])) {
                pos=i;
            }
        }
        ans++;
        add(t[pos], -1);
        t[pos]--;
        add(t[pos], 1);
        try1();

        ans=0;
        for (int i=1; i<=n; i++) {
            t[i]=0;
        }
        for (int i=0; i<k; i++) {
            for (int j=0; j<k; j++) {
                db[i][j]=0;
            }
        }
        kesz=0;
    }
    return 0;
}
/*
1
7
1 2
1 5
2 3
2 4
5 6
5 7
*/