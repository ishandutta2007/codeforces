#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[400001];
int b[400001];
const int mod=998244353;
int binpow(int a,int b){
    if (b==0) return 1ll;
    if (b%2) return (a*binpow(a,b-1ll))%mod;
    else return binpow((a*a)%mod,b/2ll);
}
int f[400001];
int rf[400001];
int cnt[400001];
int cnt1[400001];
int32_t main() {
    int n;cin>>n;
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        v.push_back({a[i],b[i]});
        cnt[a[i]]++;
        cnt1[b[i]]++;
    }
    f[0]=1ll;
    for (int i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
    sort(v.begin(),v.end());
    vector<int>u;
    int cur=1;
    int x=1;
    for (int i=1;i<n;i++){
        if (v[i].second<v[i-1].second){
            x=0;
            break;
        }
    }
    for (int i=1;i<n;i++){
        if (v[i]==v[i-1]) cur++;
        else {
            x*=f[cur];
            x%=mod;
            cur=1;
        }
    }
    x*=f[cur];
    x%=mod;

    int y=1;
    int z=1;
    for (int i=1;i<=n;i++){
        y*=f[cnt[i]];
        y%=mod;
        z*=f[cnt1[i]];
        z%=mod;
    }
    int res=((y+z-x+mod)%mod)*1ll;
    cout<<(f[n]-res+mod)%mod;
    return 0;
}


///20075213641185