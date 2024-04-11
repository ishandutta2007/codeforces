#include <bits/stdc++.h>

using namespace std;
long long n, m;
long long t[100005];
vector<pair<pair<long long, long long>, long long> >sol;
int main()
{
    ios_base::sync_with_stdio(false);
    t[100001]=-1, t[100002]=1;
    cin >> n >> m;
    for (long long i=1; i<=m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        t[a]+=c, t[b]-=c;
    }
    long long x=0, y=0;
    while(x<=n) {
        while(t[x]<=0) x++;
        while(t[y]>=0) y++;
        long long z=min(t[x], -t[y]);
        if (x>n) break;
        sol.push_back({{x, y}, z});
        t[x]-=z, t[y]+=z;
    }
    cout << sol.size() << "\n";
    for (long long i=0; i<sol.size(); i++) {
        cout << sol[i].first.first << " " << sol[i].first.second << " " << sol[i].second << "\n";
    }
    return 0;
}