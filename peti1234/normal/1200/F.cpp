#include <bits/stdc++.h>

using namespace std;
const int c=2520;
int n, ert[c], ans[c][c], si[c], q;
vector<int> sz[c];
vector<pair<int, int> > vis;
bool v[c][c], spec[c];
int dfs(int a, int b) {
    //cout << "dfs " << a << " " << b << "\n";
    if (!ans[a][b]) {
        if (v[a][b]) {
            int si=vis.size(), cnt=0;
            //cout << "..\n";
            for (int i=si-1; i>=0; i--) {
                int aa=vis[i].first, bb=vis[i].second;
                if (!spec[aa]) {
                    cnt++;
                    spec[aa]=1;
                }
                if (a==aa && b==bb) {
                    break;
                }
            }
            //cout << "valasz " << cnt << "\n";
            return cnt;
        }
        v[a][b]=true;
        vis.push_back({a, b});
        int b2=(b+ert[a])%c;
        ans[a][b]=dfs(sz[a][b2%si[a]], b2);
    }
    /*if (a==1 && b==0) {
        cout << "... " << ans[a][b] << "\n";
    }*/
    return ans[a][b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        x=(x%c+c)%c;
        ert[i]=x;
    }
    for (int i=1; i<=n; i++) {
        cin >> si[i];
        for (int j=0; j<si[i]; j++) {
            int x;
            cin >> x;
            sz[i].push_back(x);
        }
    }
    for (int kezd=1; kezd<=n; kezd++) {
        for (int ert=0; ert<c; ert++) {
            if (!v[kezd][ert]) {
                dfs(kezd, ert);
                //cout << dfs(kezd, ert) << "...\n";
                //cout << "... " << ans[kezd][ert] << "\n";
                for (auto x:vis) {
                    spec[x.first]=0;
                }
                vis.clear();
                //kezd=n+1, ert=c;
            }
        }
    }
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        b=(b%c+c)%c;
        cout << ans[a][b] << "\n";
    }
    return 0;
}
/*
4
4 -5 -3 -1
2
2 3
1
2
3
2 4 1
4
3 1 2 1
6
1 0
2 0
3 -1
4 -2
1 1
1 5
*/