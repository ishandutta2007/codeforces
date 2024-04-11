#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int par[c], t[c], pos, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {int x; cin >> x; par[x]=i;}
    for (int i=1; i<=n; i++) {
        int p, x=0, y=pos+1;
        cin >> p, p=par[p];
        while(y-x>1) {
            int z=(x+y)/2;
            if (t[z]<p) y=z;
            else x=z;
        }
        t[y]=p, pos=max(pos, y);
    }
    cout << pos << "\n";
    return 0;
}