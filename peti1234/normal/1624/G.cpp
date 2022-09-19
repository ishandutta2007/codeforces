#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, m, l[c], r[c], s[c], ki[c];
vector<int> a, b;
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
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=m; i++) {
            cin >> l[i] >> r[i] >> s[i];
            a.push_back(i);
        }
        int ans=0;
        for (int p=30; p>=0; p--) {
            int ert=(1<<p);
            for (auto x:a) {
                if ((s[x] & ert)==0) {
                    unio(l[x], r[x]);
                    b.push_back(x);
                }
            }
            bool baj=0;
            for (int i=1; i<=n; i++) {
                if (holvan(i)!=holvan(1)) {
                    baj=1;
                }
            }

            if (baj) {
                ans+=ert;
            } else {
                a=b;
            }

            b.clear();
            for (int i=1; i<=n; i++) ki[i]=0;
        }

        cout << ans << "\n";
        a.clear();
    }
    return 0;
}
/*
1
3 4
1 2 1
2 3 2
1 3 3
3 1 4
*/