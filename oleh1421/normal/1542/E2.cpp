#include <bits/stdc++.h>

typedef long long ll;
//#define endl '\n'
using namespace std;
//#define int ll
const int N=510;
const int Z=N*N;
ll mod;
ll f[N];
ll C[N][N];
ll tot[2][N*(N+1)];
ll S[2][N*(N+1)];
ll pref[2][N*(N+1)];
ll suf[2][N*(N+1)];
void calc(int c){
    int mx=(c+2)*(c+3);
    c%=2;
    S[c][0]=0;
    pref[c][0]=0;
    for (int i=1;i<=mx;i++){
        S[c][i]=(S[c][i-1]+tot[c][i])%mod;
        pref[c][i]=(pref[c][i-1]+tot[c][i]*(i*1ll))%mod;
        suf[c][i]=(suf[c][i-1]+tot[c][i]*(mx-i+1ll))%mod;
    }
}
ll get1(int c,int l,int r){
    c%=2;
    return ((pref[c][r]-pref[c][l-1]-(S[c][r]-S[c][l-1])*(l-1ll))%mod+mod)%mod;
}
ll get2(int c,int l,int r){
    int mx=(c+2)*(c+3);
    c%=2;
    return ((suf[c][r]-suf[c][l-1]-(S[c][r]-S[c][l-1])*(mx-r+0ll))%mod+mod)%mod;
}
void solve(){
    int n;cin>>n>>mod;
    C[0][0]=1;
    f[0]=1;
    for (int i=1;i<=n;i++){
        f[i]=(f[i-1]*(i*1ll))%mod;
        C[i][0]=1;
        for (int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    ll res=0ll;
    tot[0][1]=1;
    calc(0);
    for (int i=0;i<n;i++){
        int cur=(i+2)*(i+3)/2;
        int last=(i+1)*(i+2)/2;
        for (int j=0;j<=cur*2;j++){
            tot[(i+1)%2][j]=0;
        }
        ll sum=0ll;
        for (int j=-i*(i+1)/2;j<=i*(i+1)/2;j++){
            ll x=get2(i,last+j+1,last+j+i);
            if (j>0) sum=(sum+x)%mod;
            tot[(i+1)%2][j+cur]=(x+tot[i%2][j+last]*(i+1ll)+get1(i,last+j-i,last+j-1))%mod;
        }
        res+=((sum*C[n][i+1]%mod)*f[n-i-1])%mod;
        res%=mod;

        calc(i+1);
    }

    cout<<res<<endl;


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;


    while (tt--){
        solve();
    }
    return 0;
}
//50 1000000007