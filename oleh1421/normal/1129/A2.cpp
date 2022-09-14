//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
int dist[200001];
int cnt[200001];
vector<int>v;
int n,m;
int solve(int s){
    int maxx=0;
    for (int i=1;i<=n;i++){
        if (!cnt[i]) continue;
        maxx=max(maxx,(i-s+n)%n+n*(cnt[i]-1)+dist[i]);
    }
    return maxx;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        if (!dist[a]) dist[a]=(b-a+n)%n;
        else dist[a]=min(dist[a],(b-a+n)%n);
        cnt[a]++;
    }
    for (int i=1;i<=n;i++){
        cout<<solve(i)<<" ";
    }
    return 0;
}