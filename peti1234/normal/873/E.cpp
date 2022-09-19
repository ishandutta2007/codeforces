#include <bits/stdc++.h>

using namespace std;
const long long c=5002;
long long opt;
int n, maxi[c][c], ans[c], pos[c][c], h1, h2, h3;
vector<pair<int, int> > sz;
int main()
{
    cin >> n;
    sz.push_back({0, 0});
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        sz.push_back({x, i});
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=1; i<=n; i++) maxi[i][i]=sz[i-1].first-sz[i].first, pos[i][i]=i;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            pos[i][j]=pos[i][j-1];
            if (maxi[j][j]>maxi[i][j-1]) pos[i][j]=j;
            maxi[i][j]=max(maxi[i][j-1], maxi[j][j]);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int ki=min(i, j-i), na=max(i, j-i);
            int b=ki*2, a=(na+1)/2;
            if (2*ki>=na && j+a<=n) {
                b=min(n-j, b);
                int k=pos[a+j][b+j];
                long long ert=maxi[i][i]*c*c+maxi[j][j]*c+maxi[k][k];
                if (ert>opt) {
                    opt=ert;
                    h1=i, h2=j, h3=k;
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        int se=sz[i].second;
        if (i<h1) ans[se]=1;
        else if (i<h2) ans[se]=2;
        else if (i<h3) ans[se]=3;
        else ans[se]=-1;
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}