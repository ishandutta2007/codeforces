#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=66;
const ll mod=1000000007;
ll f[N],rf[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll C(int n,int k){
    if (k>n || k<0) return 0;
    return f[n]*rf[k]%mod*rf[n-k]%mod;
}

int n,m,k;
int a[N];
vector<int>v,u;
ll dp[(1<<20)];
int msk[N];
vector<int>order;
bool used[N];
void dfs(int v){
    order.push_back(v);
    used[v]=true;
    for (int to=0;to<k;to++){
        if (!used[to] && (msk[to]&msk[v])){
            dfs(to);
        }
    }
}

void solve(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    for (int i=1;i<=n;i++){
        bool rt=true;
        for (int j=1;j<i;j++){
            if (a[i]%a[j]==0){
                rt=false;
                break;
            }
        }
        if (!rt){
            v.push_back(a[i]);
        } else {
            bool need=false;
            for (int j=i+1;j<=n;j++){
                if (a[j]%a[i]==0) need=true;
            }
            if (need) u.push_back(a[i]);
        }
    }
    m=u.size();
    k=v.size();
    for (int i=0;i<k;i++){
        msk[i]=0;
        for (int j=0;j<m;j++){
            if (v[i]%u[j]==0) msk[i]|=(1<<j);
        }
    }
    ll ans=1ll;
    vector<int>sz;
    for (int i=0;i<k;i++){
        if (!used[i]){
            dfs(i);
            sz.push_back(order.size());
            int MASK=0;
            for (int j:order) MASK|=msk[j];
            dp[MASK]=1;
            for (int mask=(MASK-1)&MASK;mask>=1;mask=(mask-1)&MASK){
                dp[mask]=0;
                int cnt=0;
                for (int i:order){
                    if ((mask&msk[i])==msk[i]) cnt++;
                }
                for (int i:order){
                    if ((mask&msk[i])==msk[i]) continue;
                    if ((mask&msk[i])==0) continue;
//                    cout<<mask<<" "<<msk[i]<<endl;
                    int nw=(mask|msk[i]);
                    int cnt1=-1;
                    for (int j:order){
                        if ((mask&msk[j])==msk[j]) continue;
                        if ((nw&msk[j])==msk[j]) cnt1++;
                    }
//                    cout<<cnt1<<endl;
                    dp[mask]+=dp[nw]*C((int)order.size()-cnt-1,cnt1)%mod*f[cnt1]%mod;
                    dp[mask]%=mod;
//                    cout<<dp[mask]<<endl;
                }
            }

            ll res=0ll;
            for (int i:order){
                int nw=msk[i];
                int cnt1=-1;
                for (int j:order){
                    if ((nw&msk[j])==msk[j]) cnt1++;
                }
//                cout<<msk[i]<<" "<<dp[nw]*C((int)order.size()-1,cnt1)%mod*f[cnt1]%mod<<endl;
                res+=dp[nw]*C((int)order.size()-1,cnt1)%mod*f[cnt1]%mod;
                res%=mod;
            }
            ans*=res;
            ans%=mod;
            order.clear();
        }
    }
    ans*=f[k-(int)sz.size()];
    ans%=mod;
    for (auto i:sz){
        ans*=rf[i-1];
        ans%=mod;
    }
    cout<<ans<<endl;
//    for (int i=0;i<=k;i++){
//        for (int mask=0;mask<(1<<m);mask++) dp[i][mask]={1000000001,0};
//    }
//    dp[0][0]={0,1};
//    for (int i=0;i<k;i++){
//        for (int mask=0;mask<(1<<m);mask++){
//            auto cur=dp[i][mask];
//            upd(dp[i+1][mask],cur);
//            int nw=mask;
//            for (int j=0;j<m;j++){
//                if (v[i]%u[j]==0) nw|=(1<<j);
//            }
//            cur.first++;
//            upd(dp[i+1][nw],cur);
//        }
//    }
//    cout<<dp[k][(1<<m)-1].second<<endl;


}
int32_t  main()
{
    f[0]=1ll;
    for (int i=1;i<N;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    for (int i=0;i<N;i++){
        rf[i]=binpow(f[i],mod-2);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
4
1 2 5 2
BRBR
**/