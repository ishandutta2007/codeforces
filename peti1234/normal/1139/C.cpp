#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int> sz[100001];
bool v[100001];
int cnt[100001];
vector<int> q;
long long mod=1000000007;
long long sum=1;
int dfs(int a)
{
    int hm=1;
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            hm+=dfs(x);
        }
    }
    return hm;
}
int main()
{
    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int a, b;
        bool c;
        cin >> a >> b >> c;
        if (c==0) {
            sz[a].push_back(b);
            sz[b].push_back(a);

        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            int x=dfs(i);
            cnt[x]++;
            if (cnt[x]==1) {
                q.push_back(x);
            }
        }
    }
    for (int i=1; i<=k; i++) {
        sum*=n;
        sum%=mod;
    }
    for (int i=0; i<q.size(); i++) {
        int y=q[i];

        long long p=1;
        for (int i=1; i<=k; i++) {
            p*=y;
            p%=mod;
        }
        sum-=p*cnt[y];
    }
    while(sum<0) {
        sum+=mod;
    }

    cout << sum << "\n";
    return 0;
}