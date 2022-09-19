#include <bits/stdc++.h>

using namespace std;
const int c=2002, k=10;
int bal[k], jobb[k], kis[k], nagy[k], t[c][c], n, sol[k], w;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=0; i<k; i++) {
            kis[i]=n, bal[i]=n, nagy[i]=0, jobb[i]=0, sol[i]=0;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                char c; cin >> c;
                int x=c-'0';
                t[i][j]=x;
                kis[x]=min(kis[x], i), nagy[x]=max(nagy[x], i);
                bal[x]=min(bal[x], j), jobb[x]=max(jobb[x], j);
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                int x=t[i][j], mag=max(i-1, n-i), szel=max(j-1, n-j);
                sol[x]=max({sol[x], mag*(j-bal[x]), mag*(jobb[x]-j), szel*(i-kis[x]), szel*(nagy[x]-i)});
            }
        }
        for (int i=0; i<k; i++) {
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
1
3
000
122
001
*/