#include <bits/stdc++.h>

using namespace std;
const int c=1005;
long long pro[1000005], oszt[1000005], n, m, ert[c][c];
long long cnt, sqx, sumx, sqy, sumy, sum, mod=998244353;
vector<pair<int, pair<int, int> > > sz;
long long po(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=2; i<=n*m; i++) {
        for (int j=2*i; j<=n*m; j+=i) {
            pro[j]=i;
        }
    }
    for (int i=1; i<=n*m; i++) {
        if (!pro[i]) oszt[i]=po(i);
        else oszt[i]=oszt[pro[i]]*oszt[i/pro[i]]%mod;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x;
            cin >> x;
            sz.push_back({x, {i, j}});
        }
    }
    sort(sz.begin(), sz.end());

    int pos=0;
    for (int i=0; i<n*m; i++) {
        long long id=sz[i].first, a=sz[i].second.first, b=sz[i].second.second;
        long long val=(sum+sqx+sqy+cnt*a*a+cnt*b*b-2*a*sumx-2*b*sumy)%mod+mod;
        ert[a][b]=val*oszt[cnt]%mod;
        if (i+1<n*m && sz[i+1].first>id) {
            while (pos<=i) {
                long long a=sz[pos].second.first, b=sz[pos].second.second;
                cnt++;
                sum+=ert[a][b];
                sqx+=a*a, sqy+=b*b;
                sumx+=a, sumy+=b;
                if (sum>=mod) sum-=mod;
                pos++;
            }
        }
    }


    int r, c;
    cin >> r >> c;
    cout << ert[r][c] << "\n";
    return 0;
}