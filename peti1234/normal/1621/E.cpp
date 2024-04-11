#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, m, a[c], b[c], bb[c], kezd, veg;
bool baj;
long long sum[c], db[c];
vector<int> sz[c];
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=m; i++) {
            cin >> db[i];
            for (int j=1; j<=db[i]; j++) {
                int x;
                cin >> x;
                sz[i].push_back(x);
                sum[i]+=x;
            }
            bb[i]=b[i]=(sum[i]+db[i]-1)/db[i];
            //cout << "ertek " << i << " " << b[i] << "\n";
        }

        sort(a+1, a+n+1), reverse(a+1, a+n+1);
        sort(b+1, b+m+1), reverse(b+1, b+m+1);
        s.insert(a[1]);
        for (int i=1; i<=m; i++) {
            if (b[i]>a[i]) {
                if (!kezd) kezd=a[i];
                veg=a[i];
            }
            if (i>1 && b[i]>a[i-1]) {
                baj=1;
            }
            if (i<m && b[i]>a[i+1]) {
                s.insert(a[i+1]);
            }
        }
        for (int i=1; i<=m; i++) {
            int x=bb[i];
            for (auto p:sz[i]) {
                int y=(sum[i]-p+db[i]-2)/(db[i]-1);
                if (baj) cout << 0;
                else if (kezd) cout << (x>kezd && y<=veg ? 1 : 0);
                else cout << (x>y || s.lower_bound(x)==s.lower_bound(y) ? 1 : 0);
            }
        }
        cout << "\n";

        for (int i=1; i<=n; i++) a[i]=0;
        for (int i=1; i<=m; i++) {
            b[i]=0, bb[i]=0, sum[i]=0, db[i]=0;
            sz[i].clear();
        }
        s.clear();
        kezd=0, veg=0, baj=0;
    }
    return 0;
}
/*
1
7 4
8 5 8 12 8 19 6
5
1 2 3 4 5
5
19 15 23 11 27
5
5 8 8 8 8
4
8 8 8 9
*/