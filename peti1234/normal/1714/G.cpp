#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, ans[c], fen[c], szint, sum;
vector<long long> g;
vector<pair<int, pair<int, int> > > sz[c];

int lsb(int a) {
    return (a & -a);
}
void add(int a, long long b) {
    while (a<=n) {
        fen[a]+=b;
        a+=lsb(a);
    }
}
long long ask(int a) {
    long long ans=0;
    while (a) {
        ans+=fen[a];
        a-=lsb(a);
    }
    return ans;
}

void dfs(int a) {

    int lo=0, hi=szint+1, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (ask(mid)<=sum) lo=mid;
        else hi=mid;
    }
    ans[a]=lo;


    for (auto f:sz[a]) {
        int kov=f.first, p=f.second.first, q=f.second.second;
        sum+=p;
        szint++;
        add(szint, q);
        dfs(kov);
        add(szint, -q);
        szint--;
        sum-=p;
    }
}
void solve() {
    cin >> n;
    for (int i=2; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back({i, {b, c}});
    }
    dfs(1);
    for (int i=2; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    for (int i=1; i<=n; i++) {
        ans[i]=0, sz[i].clear();
    }
    g.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}