#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, sum, pro[c], db[c], maxi[c], mod=998244353;
vector<int> sz[c];
vector<pair<int, int> > sz2[c];
bool v[c];
long long oszt(long long a) {
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
void dfs(int a, long long ert) {
    sum=(sum+ert)%mod;
    v[a]=true;
    int si=sz[a].size();
    for (int i=0; i<si; i++) {
        int x=sz[a][i];
        if (!v[x]) {
            long long c=sz2[a][i].first, d=sz2[a][i].second;
            long long cc=c, dd=d;
            while (cc>1) {
                int s=pro[cc];
                db[s]++;
                maxi[s]=max(maxi[s], db[s]);
                cc/=s;
            }
            while (dd>1) {
                int s=pro[dd];
                db[s]--;
                maxi[s]=max(maxi[s], db[s]);
                dd/=s;
            }
            dfs(x, ert*d%mod*oszt(c)%mod);
            cc=c;
            while (cc>1) {
                int s=pro[cc];
                db[s]--;
                cc/=s;
            }
            dd=d;
            while (dd>1) {
                int s=pro[dd];
                db[s]++;
                dd/=s;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=2; i<=n; i++) {
            if (!pro[i]) {
                for (int j=i; j<=n; j+=i) {
                    pro[j]=i;
                }
            }
        }
        for (int i=1; i<n; i++) {
            long long a, b, c, d;
            cin >> a >> b >> c >> d;
            long long s=__gcd(c, d);
            c/=s, d/=s;
            sz[a].push_back(b), sz[b].push_back(a);
            sz2[a].push_back({c, d}), sz2[b].push_back({d, c});
        }
        dfs(1, 1);
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=maxi[i]; j++) {
                sum=sum*i%mod;
            }
        }
        cout << sum << "\n";

        for (int i=1; i<=n; i++) {
            db[i]=0, maxi[i]=0, pro[i]=0;
            v[i]=0, sz[i].clear(), sz2[i].clear();
        }
        sum=0;
    }
    return 0;
}
/*
1
8
5 4 2 3
6 4 5 4
1 3 5 2
6 8 2 1
3 5 3 4
3 2 2 5
6 7 4 3
*/