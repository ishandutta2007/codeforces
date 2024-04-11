#include <bits/stdc++.h>

using namespace std;
int w, n, db;
bool k[12];
int t[1002], ans[1002];
int h[12], rev[12];
vector<int> v{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<11; i++) {
        for (int j=2*v[i]; j<=1000; j+=v[i]) ans[j]=i+1;
    }
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=0; i<=11; i++) h[i]=0, rev[i]=0, k[i]=0;
        db=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            int x=ans[t[i]];
            if (!k[x]) h[db]=x, rev[x]=db, k[x]=true, db++;
        }
        cout << db << "\n";
        for (int i=1; i<=n; i++) {
            cout << rev[ans[t[i]]]+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}