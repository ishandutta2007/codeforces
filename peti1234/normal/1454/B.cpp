#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, id[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) id[i]=0;
        for (int i=1; i<=n; i++){
            int x; cin >> x;
            if (!id[x]) id[x]=i;
            else id[x]=-1;
        }
        bool jo=0;
        for (int i=1; i<=n; i++) {
            if (!jo && id[i]>0) {
                jo=1;
                cout << id[i] << "\n";
            }
        }
        if (!jo) {
            cout << -1 << "\n";
        }
    }
    return 0;
}