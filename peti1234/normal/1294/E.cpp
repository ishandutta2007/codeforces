#include <bits/stdc++.h>

using namespace std;
vector<int> sz[200001];
long long sum, maxi=0;
long long  n, m;
long long pl[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    sum=n*m;
    for (long long i=1; i<=n; i++) {
        long long db=0;
        sz[i].push_back(0);
        for (long long j=1; j<=m; j++) {
            long long a;
            cin >> a;
            if (n==1) if (a==j) db++;
            if (j==m) sz[i][0]=a;
            else sz[i].push_back(a);
        }
        if (n==1) {
            cout << m-db << "\n";
            return 0;
        }
    }
    for (long long j=0; j<m; j++) {
        maxi=0;
        for (long long i=0; i<n; i++) pl[i]=0;
        for (long long i=1; i<=n; i++) {
            long long x=sz[i][j];
            if (x%m==j && x<=n*m) {
                long long  y=(i-(x-1)/m-1+n*200000)%n;
                pl[y]++;
            }
        }
        for (long long i=0; i<n; i++) maxi=max(maxi, pl[i]-i);
        sum-=maxi;
    }
    cout << sum << "\n";
    return 0;
}