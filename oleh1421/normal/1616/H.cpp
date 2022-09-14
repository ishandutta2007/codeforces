#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
const int N=150010;
const int L=29;
const int T_SZ=N*30;
const ll inf=1000000000000000001ll;
const ll mod=998244353;
int a[N];
int TOT=1;
int go[T_SZ][2];
int cnt[T_SZ];
int x;
ll pw2[N];
ll solve(int l,int r,int bt){
//    cout<<l<<" "<<r<<" "<<bt<<endl;
    if (!l || !r || bt==-1) {
        if (l==r) return (pw2[cnt[l]]-1ll);
        return ((pw2[cnt[l]]-1ll)*(pw2[cnt[r]]-1ll));
    }
    if (x&(1<<bt)){
        if (l==r) return (solve(go[l][0],go[l][1],bt-1)+pw2[cnt[go[l][0]]]+pw2[cnt[go[l][1]]]-2ll)%mod;
        ll a=solve(go[l][0],go[r][1],bt-1)+pw2[cnt[go[l][0]]]+pw2[cnt[go[r][1]]]-1ll;
        ll b=(solve(go[l][1],go[r][0],bt-1)+pw2[cnt[go[l][1]]]+pw2[cnt[go[r][0]]]-1ll);
        return (a*b-pw2[cnt[l]]-pw2[cnt[r]]+1ll+mod*2ll)%mod;
    } else {
        if (l==r) return (solve(go[l][0],go[l][0],bt-1)+solve(go[l][1],go[l][1],bt-1))%mod;
        else {
            ll a=(solve(go[l][0],go[r][0],bt-1))%mod;
            ll b=(solve(go[l][1],go[r][1],bt-1))%mod;
            return (a+b)%mod;
        }
    }

}
void solve(){
    int n;cin>>n>>x;
    pw2[0]=1ll;
    for (int i=1;i<=n;i++){
        pw2[i]=(pw2[i-1]*2ll)%mod;
        cin>>a[i];
        int v=1;
        cnt[v]++;
        for (int j=L;j>=0;j--){
            int cur=(a[i]>>j)%2;
            if (!go[v][cur]) go[v][cur]=++TOT;
            v=go[v][cur];
            cnt[v]++;
        }
    }
    cout<<solve(1,1,L)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
3 2
0 1 2


**/