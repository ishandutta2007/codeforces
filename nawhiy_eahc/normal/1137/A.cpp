#include <bits/stdc++.h>

using namespace std;

int a[1002][1002], b[1002], c[1002];
int cmp[1002][1002], cmp2[1002][1002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m ; cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        vector<int> v, u; v.clear(), u.clear();
        for(int j=1;j<=m;j++){
            v.push_back(a[i][j]);
        }

        sort(v.begin(), v.end());
        for(int t : v){
            if(u.empty() || u.back() != t) u.push_back(t);
        }

        for(int j=1;j<=m;j++){
            cmp[i][j] = lower_bound(u.begin(), u.end(), a[i][j]) - u.begin();
        }
        b[i] = 0;
        for(int j=1;j<=m;j++) b[i] = max(b[i], cmp[i][j]);
    }

    for(int j=1;j<=m;j++){
        vector<int> v, u; v.clear(), u.clear();
        for(int i=1;i<=n;i++){
            v.push_back(a[i][j]);
        }

        sort(v.begin(), v.end());
        for(int t : v){
            if(u.empty() || u.back() != t) u.push_back(t);
        }
        for(int i=1;i<=n;i++){
            cmp2[i][j] = lower_bound(u.begin(), u.end(), a[i][j]) - u.begin();
        }
        c[j] = 0;
        for(int i=1;i<=n;i++) c[j] = max(c[j], cmp2[i][j]);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int ans = 0;
            if(cmp[i][j] > cmp2[i][j]) ans = max(cmp[i][j] + c[j] - cmp2[i][j], b[i]);
            else ans = max(c[j], b[i] - cmp[i][j] + cmp2[i][j]);

            cout << ans + 1 << " ";
        }
        cout << "\n";
    }
}