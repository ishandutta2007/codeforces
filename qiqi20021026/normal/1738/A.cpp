#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int mod=998244353;
#define N 120000

LL a[N],b[N];

void solve(){
    LL ans=0;
    int n; cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    vector<int> f[2];
    for (int i=1;i<=n;++i){
        cin>>b[i];
        f[a[i]].push_back(b[i]);
    }
    sort(f[0].begin(),f[0].end(),greater<int>());
    sort(f[1].begin(),f[1].end(),greater<int>());
    if (f[0].size()){
        LL sum=*f[0].rbegin(),lst=0;
        for (int i=0;i<n;++i){
            if (i<f[1].size()){
                sum+=f[1][i]*(1+(lst!=1));
                lst=1;
            }
            if (i+1<f[0].size()){
                sum+=f[0][i]*(1+(lst!=0));
                lst=0;
            }
        }
        ans=max(ans,sum);
    }
    if (f[1].size()){
        LL sum=*f[1].rbegin(),lst=1;
        for (int i=0;i<n;++i){
            if (i<f[0].size()){
                sum+=f[0][i]*(1+(lst!=0));
                lst=0;
            }
            if (i+1<f[1].size()){
                sum+=f[1][i]*(1+(lst!=1));
                lst=1;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}