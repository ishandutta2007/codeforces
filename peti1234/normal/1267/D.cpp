#include <bits/stdc++.h>

using namespace std;
const int c=300;
int n, kell[c], ad[c], kesz[8];
bool ct[c], jo[c];
vector<pair<int, int> > ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        kell[i]=4*a+2*b+c;
        if (!kell[i]) jo[i]=1;
    }
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ad[i]=4*a+2*b+c;
        ct[i]=1;
    }
    kesz[7]=1;
    jo[1]=1;
    for (int l=1; l<=10; l++) {
        for (int i=1; i<=n; i++) {
            if (jo[i]) continue;
            if (kesz[kell[i]]) {
                jo[i]=1;
                ans.push_back({kesz[kell[i]], i});
                int kov=kell[i]&ad[i];
                if (!kesz[kov]) {
                    kesz[kov]=i;
                }
            }
            if (!jo[i] && l>=7 && __builtin_popcount(kell[i])==2) {
                int a=(kell[i]%2 ? 1 : 2), b=(kell[i]<4 ? 2 : 4);
                if (kesz[a] && kesz[b]) {
                    ans.push_back({kesz[a], i});
                    ans.push_back({kesz[b], i});
                    jo[i]=1;
                    ct[i]=0;
                    kesz[kell[i]]=i;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (!jo[i]) {
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << "Possible\n";
    for (int i=1; i<=n; i++) {
        cout << ct[i] << " ";
    }
    cout << "\n";
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}
/*
8
1 1 1
1 1 1
1 1 1
0 0 1
0 1 0
0 1 1
0 1 1
0 1 1

1 1 1
0 0 1
0 1 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0

*/