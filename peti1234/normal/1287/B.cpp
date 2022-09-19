#include <bits/stdc++.h>

using namespace std;
int db, n, m, x, y;
vector<long long> sz;
long long h[32];
char c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m, h[0]=1;
    for (int i=1; i<=30; i++) h[i]=h[i-1]*3;
    for (int i=1; i<=n; i++) {
        long long ert=0;
        for (int j=0; j<m; j++) {
            cin >> c;
            if (c=='E') ert+=h[j];
            if (c=='T') ert+=2*h[j];
        }
        sz.push_back(ert);
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            long long a=sz[i], b=sz[j], ert=0;
            for (int k=0; k<m; k++) {
                int x=a%3, y=b%3, z=(3-(x+y)%3)%3;
                ert+=z*h[k];
                a/=3, b/=3;
            }
            x=-1, y=n;
            while(y-x>1) {
                int z=(x+y)/2;
                if (sz[z]==ert) db++;
                if (sz[z]<ert) x=z;
                else y=z;
            }
        }
    }
    cout << db/3 << "\n";
    return 0;
}