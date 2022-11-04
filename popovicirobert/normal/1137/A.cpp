#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    vector < vector <int> > mat(n + 1, vector <int>(m + 1));
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }

    vector < vector <int> > idl(n + 1, vector <int>(m + 1)), idc;
    idc = idl;

    vector <int> szl(n + 1), szc(m + 1);

    for(i = 1; i <= n; i++) {
        vector <int> nrm;
        for(j = 1; j <= m; j++) {
            nrm.push_back(mat[i][j]);
        }
        sort(nrm.begin(), nrm.end());
        nrm.resize(unique(nrm.begin(), nrm.end()) - nrm.begin());

        szl[i] = nrm.size();
        for(j = 1; j <= m; j++) {
            idl[i][j] = lower_bound(nrm.begin(), nrm.end(), mat[i][j]) - nrm.begin();
        }
    }

    for(j = 1; j <= m; j++) {
        vector <int> nrm;
        for(i = 1; i <= n; i++) {
            nrm.push_back(mat[i][j]);
        }
        sort(nrm.begin(), nrm.end());
        nrm.resize(unique(nrm.begin(), nrm.end()) - nrm.begin());

        szc[j] = nrm.size();
        for(i = 1; i <= n; i++) {
            idc[i][j] = lower_bound(nrm.begin(), nrm.end(), mat[i][j]) - nrm.begin();
        }
    }

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            int ans = max(szl[i], szc[j]);
            ans = max(ans, max(idl[i][j] + szc[j] - idc[i][j], idc[i][j] + szl[i] - idl[i][j]));
            cout << ans << " ";
        }
        cout << "\n";
    }

    //cin.close();
    //cout.close();
    return 0;
}