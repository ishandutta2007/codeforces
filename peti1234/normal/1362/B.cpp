#include <bits/stdc++.h>

using namespace std;
const int c=1024;
int w, n, t[c+1];
bool v[c], jo, f;
int main()
{
    cin >> w;
    while(w--) {
        for (int i=0; i<c; i++) v[i]=0;
        cin >> n, jo=0;
        for (int i=1; i<=n; i++) cin >> t[i], v[t[i]]=true;
        for (int i=1; i<c; i++) {
            f=0;
            for (int j=1; j<=n; j++) if (v[t[j]]!=v[(t[j]^i)]) f=1;
            if (!f) cout << i << "\n", jo=1, i=c;
        }
        if (!jo) cout << -1 << "\n";
    }
    return 0;
}
/*
1 2 1 2
*/