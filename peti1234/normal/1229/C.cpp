#include <bits/stdc++.h>
 
using namespace std;
vector<long long> sz[100001];
long long szom[100001];
long long db[100001];
long long n, m, q, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (long long i=1; i<=m; i++) {
        long long a, b;
        cin >> a >> b;
        if (b>a) {
            swap(a, b);
        }
        sz[b].push_back(a);
        db[b]++;
        szom[a]++, szom[b]++;
    }
    for (long long i=1; i<=n; i++) {
        ans+=db[i]*(szom[i]-db[i]);
    }
    cout << ans << "\n";
    cin >> q;
    for (long long i=1; i<=q; i++) {
        long long x;
        cin >> x;
        for (long long i=0; i<sz[x].size(); i++) {
            long long a=sz[x][i];
            db[a]++;
            sz[a].push_back(x);
            ans+=szom[a]+1;
            ans-=2*db[a];
        }
        ans-=db[x]*(szom[x]-db[x]);
        db[x]=0;
        sz[x].clear();
        cout << ans << "\n";
    }
    return 0;
}