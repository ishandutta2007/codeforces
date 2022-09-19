#include <bits/stdc++.h>

using namespace std;
int w, n, k;
string s[2];
vector<pair<int, int> > ans[2];
void valt(int id, int st, bool dir) {
    int cnt=0, kezd, veg;
    for (int i=0; i<n; i++) {
        if (s[id][i]=='1') {
            cnt++;
            if (cnt==st) {
                kezd=i;
            }
            if (cnt==st+k-1) {
                veg=i;
            }
        }
    }
    if (dir==0) {
        while (veg+1<n && s[id][veg+1]=='0') {
            veg++;
        }
    } else {
        while (kezd-1>=0 && s[id][kezd-1]=='0') {
            kezd--;
        }
    }
    ans[id].push_back({kezd+1, veg+1});
    reverse(s[id].begin()+kezd, s[id].begin()+veg+1);
}
void solve(int id) {
    int cnt=0;
    for (auto x:s[id]) {
        if (x=='1') {
            cnt++;
        }
    }
    if (k==0 || k>cnt) {
        return;
    }
    if (k==cnt) {
        valt(id, 1, 1);
        int len=n;
        while (s[id][len-1]=='0') {
            len--;
        }
        string a=s[id].substr(0, len), b=a;
        reverse(b.begin(), b.end());
        if (b<a) {
            valt(id, 1, 1);
        }
        return;
    }
    for (int i=cnt-k+1; i>=1; i--) {
        valt(id, i, 0);
    }
    for (int i=1; i<=k; i++) {
        valt(id, 1, 0);
        valt(id, 2, 1-k%2);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int tc=1; tc<=w; tc++) {
        cin >> n >> k;
        cin >> s[0] >> s[1];
        solve(0), solve(1);
        if (s[0]==s[1]) {
            cout << ans[0].size()+ans[1].size() << "\n";
            for (auto x:ans[0]) {
                cout << x.first << " " << x.second << "\n";
            }
            reverse(ans[1].begin(), ans[1].end());
            for (auto x:ans[1]) {
                cout << x.first << " " << x.second << "\n";
            }
        } else {
            cout << -1 << "\n";
        }
        ans[0].clear(), ans[1].clear();
    }
    return 0;
}