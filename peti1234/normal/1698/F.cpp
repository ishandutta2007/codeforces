#include <bits/stdc++.h>

using namespace std;
const int c=505;
int n, t[c], f[c];
multiset<pair<int, int> > pa, pb;
vector<pair<int, int> > ans;
int lep(int a, int b) {
    ans.push_back({a, b});
    reverse(t+a, t+b+1);
}
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (i>1) {
            int a=t[i], b=t[i-1];
            if (a>b) swap(a, b);
            pa.insert({a, b});
        }
    }
    for (int i=1; i<=n; i++) {
        cin >> f[i];
        if (i>1) {
            int a=f[i], b=f[i-1];
            if (a>b) swap(a, b);
            pb.insert({a, b});
        }
    }
    if (pa!=pb || t[1]!=f[1]) {
        cout << "NO\n";
    } else {
        while (true) {
            int pos=1;
            while (pos<=n && t[pos]==f[pos]) pos++;
            if (pos==n+1) break;
            int ert=f[pos-1], cel=f[pos];
            bool jo=0;
            for (int i=pos; i<n; i++) {
                if (!jo && t[i]==cel && t[i+1]==ert) {
                    lep(pos-1, i+1);
                    jo=1;
                }
            }
            if (!jo) {
                int pos2=0;
                for (int i=pos; i<n; i++) {
                    if (!pos2 && t[i]==ert && t[i+1]==cel) {
                        pos2=i;
                    }
                }
                for (int a=pos2; a>=pos-1; a--) {
                    for (int b=pos2+1; b<=n; b++) {
                        if (!jo && t[a]==t[b]) {
                            lep(a, b);
                            jo=1;
                        }
                    }
                }
            }
            if (!jo) {
                exit(0);
            }
        }
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << x.first << " " << x.second << "\n";
        }
    }


    for (int i=1; i<=n; i++) {
        t[i]=0, f[i]=0;
    }
    pa.clear(), pb.clear();
    ans.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
3 1
2 1 3
3 -1 -1
*/