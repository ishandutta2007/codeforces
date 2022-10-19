#include<bits/stdc++.h>
#define int long long
using namespace std;


const int N=100007;
const int INF=LLONG_MAX/10;
const int mod=998244353;

int n;
int a[N],b[N];
vector<int> cnt[2];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _;
    cin>>_;
    while (_--){
        int ans=0;
        cin>>n;
        for (int i=0;i<n;++i) cin>>a[i];
        for (int i=0;i<n;++i) cin>>b[i], ans+=b[i];
        for (int i=0;i<2;++i) cnt[i].clear();
        for (int i=0;i<n;++i) cnt[a[i]].push_back(b[i]);
        for (int i=0;i<2;++i) sort(cnt[i].begin(), cnt[i].end());
        for (int i=0;i<2;++i) reverse(cnt[i].begin(), cnt[i].end());
        int k1=cnt[0].size(), k2=cnt[1].size();
        for (int i=0;i<min(k1,k2);++i) ans+=cnt[0][i]+cnt[1][i];
        if (k1==k2) ans-=min(cnt[0][k1-1],cnt[1][k1-1]);
        cout<<ans<<"\n";
    }
}