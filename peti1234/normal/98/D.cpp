#include <bits/stdc++.h>

using namespace std;
vector<int> sz[4];
vector<pair<int, int> > ans;
int n, t[22];
void lep(int a, int b) {
    ans.push_back({a, b});
    sz[b].push_back(sz[a].back());
    sz[a].pop_back();
}
void solve2(int a, int kezd, int veg) {
    if (!a) {
        return;
    }
    int cel=a, kov=0, kov2=0;
    for (int i=1; i<sz[kezd].size(); i++) {
        int s=sz[kezd][i];
        if (t[s]==t[a]) {
            cel=s;
        }
        if (t[s]<t[a] && !kov) {
            kov=s;
        }
    }
    int k=6-kezd-veg;
    //cout << "solve2 " << a << " " << kezd << " " << veg << " " << kov << "\n";
    solve2(kov, kezd, k);
    for (int i=0; i<=abs(cel-a); i++) {
        lep(kezd, veg);
    }
    for (auto x:sz[k]) {
        if (t[x]<t[a]) {
            kov2=x;
            break;
        }
    }
    solve2(kov2, k, veg);
}
void solve(int a) {
    int kezd=0, veg=3, k;
    for (int i=1; i<=3; i++) {
        for (auto j:sz[i]) {
            if (j==a) {
                kezd=i;
            }
        }
    }
    //cout << "solve " << a << " " << kezd << " " << veg << "\n";
    if (kezd==veg) {
        return;
    }

    k=6-kezd-veg;
    int cel=a, kov=0, skov=0;
    for (int i=1; i<sz[kezd].size(); i++) {
        int s=sz[kezd][i];
        if (sz[kezd][i-1]==a) {
            skov=s;
        }
        if (t[s]==t[a]) {
            cel=s;
        }
        if (t[s]<t[a] && !kov) {
            kov=s;
        }
    }
    if (cel>a && kov) {
        //cout << "spec " << a << "\n";
        solve2(kov, kezd, veg);
        for (int i=0; i<=abs(cel-a); i++) {
            lep(kezd, k);
        }
        int kov2=0;
        for (int i=0; i<sz[veg].size(); i++) {
            if (t[sz[veg][i]]<t[a]) {
                kov2=sz[veg][i];
                break;
            }
        }
        solve2(kov2, veg, kezd);
        for (int i=0; i<=abs(cel-a); i++) {
            lep(k, veg);
        }
        return;
    }
    solve2(skov, kezd, k);
    lep(kezd, veg);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sz[1].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        solve(i);
        //break;
    }
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}
/*
6
3 3 3 2 1 1
*/