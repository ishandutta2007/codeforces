#include <bits/stdc++.h>

using namespace std;
int n, d, mini, h, asz;
vector<int> sz[5001];
int main()
{
    ios_base::sync_with_stdio(false);
    sz[0].push_back(1);
    int w;
    cin >> w;
    while(w--) {
        cin >> n >> d;
        n--, mini=0, h=n, asz=1;
        for (int i=1; i<=n; i++) sz[i].clear();
        for (int i=1; i<20; i++) {
            int db=min(h, (1<<i));
            mini+=i*db, h-=db;
        }
        if (d<mini || n*(n+1)/2<d) cout << "NO" << "\n";
        else {
            cout << "YES" << "\n";
            for (int i=2; i<=n+1; i++) {
                int r=n+2-i;
                if ((asz*r+r*(r-1)/2)<d) asz++;
                int si=sz[asz].size(), el=sz[asz-1].size();
                cout << sz[asz-1][si/2] << " ";
                sz[asz].push_back(i), d-=asz;
                if (el*2==sz[asz].size()) asz++;
            }
            cout << "\n";
        }
    }
    return 0;
}