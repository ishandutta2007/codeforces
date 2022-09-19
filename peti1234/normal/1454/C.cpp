#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, el[c], db[c], mini, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, mini=n;
        for (int i=1; i<=n; i++) el[i]=0, db[i]=1;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            if (el[x]!=i-1) db[x]++;
            el[x]=i;
            if (i==n) db[x]--;
        }
        for (int i=1; i<=n; i++) {
            if (el[i]) mini=min(mini, db[i]);
        }
        cout << mini << "\n";
    }
    return 0;
}