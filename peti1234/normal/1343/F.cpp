#include <bits/stdc++.h>

using namespace std;
int w, n;
bool o[202][202], v[202][202], jo;
int od[202], db[202], ans[202], pos[202], x, regi, uj;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<n; i++) {
            for (int j=1; j<=n; j++) o[i][j]=0;
            cin >> od[i];
            for (int j=1; j<=od[i]; j++) cin >> x, o[i][x]=1;
        }
        for (int el=1; el<=n; el++) {
            for (int i=1; i<n; i++) for (int j=1; j<=n; j++) v[i][j]=o[i][j], db[i]=od[i];
            jo=1, regi=el, uj=0, ans[1]=el, pos[el]=1;
            for (int j=2; j<=n; j++) {
                for (int k=1; k<n; k++) {
                    if (v[k][regi]) v[k][regi]=0, db[k]--;
                    if (db[k]==1) for (int i=1; i<=n; i++) if (v[k][i]) uj=i;
                }
                ans[j]=uj, pos[uj]=j, regi=uj;
            }
            for (int i=1; i<=n; i++) if (!ans[i] || pos[ans[i]]!=i) jo=0;
            for (int i=1; i<n; i++) {
                int mini=n, maxi=0;
                for (int j=1; j<=n; j++) if (o[i][j]) mini=min(mini, pos[j]), maxi=max(maxi, pos[j]);
                if (mini+od[i]!=maxi+1) jo=0;
            }
            if (jo) {
                for (int i=1; i<=n; i++) cout << ans[i] << " ";
                break;
            }
        }
        cout << "\n";
    }
	return 0;
}
/*
1 5
2 2 5
3 2 3 5
4 2 3 4 5
5 1 2 3 4 5
*/