#include <bits/stdc++.h>

using namespace std;
int w, n, mini;
int t[200001], c[200001];
bool v[200001];
vector<int> sz[200001];
void ker(int a) {
    int p=a, db=1;
    while(t[p]!=a) {
        v[p]=true;
        p=t[p], db++;
    }
    v[p]=true;
    for (int i=1; i<=db; i++) {
        if (db%i==0) {
            for (int i=0; i<db; i++) sz[i].clear();
            p=a;
            for (int j=0; j<db; j++) {
                sz[j%i].push_back(c[p]);
                p=t[p];
            }
            for (int j=0; j<i; j++) {
                bool f=true;
                for (int k=1; k<sz[j].size(); k++) {
                    if (sz[j][k]!=sz[j][k-1]) f=false;
                }
                if (f) mini=min(mini, i);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        mini=n;
        for (int i=1; i<=n; i++) cin >> t[i], v[i]=false;
        for (int i=1; i<=n; i++) cin >> c[i];
        for (int i=1; i<=n; i++) {
            if (!v[i]) ker(i);
        }
        cout << mini << "\n";
    }
    return 0;
}