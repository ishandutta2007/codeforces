#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define M 998244353

int n, k, m;

vector<pair<int,int>> vb[30];
vector<pair<int,int>> vw[30];

int bb[505050];
int qq[505050];
ll dd[505050][2];
ll ss[505050];

ll calc(int b) {
    sort(vb[b].begin(),vb[b].end());
    int j = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        while (j < vb[b].size() && vb[b][j].first == i) {
            mx = max(mx,vb[b][j].second);
            j++;
        }
        bb[i] = i <= mx;
    }
    sort(vw[b].begin(),vw[b].end());
    mx = 0;
    for (int i = 1; i <= n; i++) {
        qq[i] = 0;
    }
    for (int i = 0; i < vw[b].size(); i++) {
        int s = -vw[b][i].second;
        if (s > mx) {
            qq[vw[b][i].first] = s;
            mx = s;
        }
    }
    dd[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        // 0
        dd[i][0] = 0;
        if (!bb[i]) {
            dd[i][0] += dd[i-1][0];
            dd[i][0] += dd[i-1][1];
            dd[i][0] %= M;
        }
        // 1
        dd[i][1] = 0;
        if (qq[i] == 0) {
            dd[i][1] += dd[i-1][0];
            dd[i][1] += dd[i-1][1];
            dd[i][1] %= M;
        } else {
            /*for (int k = i-1; k >= qq[i]; k--) {
                dd[i][1] += dd[k][0];
                dd[i][1] %= M;
            }*/
            ll hh = ((ss[i-1]-ss[qq[i]-1])%M+M)%M;
            dd[i][1] += hh;
            dd[i][1] %= M;
        }
        ss[i] = ss[i-1]+dd[i][0];
        ss[i] %= M;
    }
    return (dd[n][0]+dd[n][1])%M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        for (int b = 0; b < k; b++) {
            if (x&(1<<b)) vb[b].push_back({l,r});
            else vw[b].push_back({r,-l});
        }
    }
    ll u = 1;
    for (int b = 0; b < k; b++) {
        u *= calc(b);
        u %= M;
    }
    cout << u << "\n";
}