#include <bits/stdc++.h>

using namespace std;
int q, n, m, k, maxi;
int t[3502];
int mini[3502];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n >> m >> k;
        maxi=0, k=min(k, m-1);
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=0; i<m; i++) mini[i]=max(t[i+1], t[n-m+1+i]);
        for (int i=0; i<=k; i++) {
            int ans=INT_MAX;
            for (int j=0; j<=m-k-1; j++) {
                ans=min(ans, mini[i+j]);
            }
            maxi=max(maxi, ans);
        }
        cout << maxi << "\n";
    }
    return 0;
}
/*
1
6 4 2
2 9 2 3 8 5
*/