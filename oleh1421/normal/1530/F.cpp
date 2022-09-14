//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const int mod=31607;
using namespace std;
mt19937 rnd(time(NULL));
const int N=25;
int a[N][N];
int binpow(int a,int b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2);
}
bool used[N][N];
int r[N][(1<<21)];
int c[N];
int mult1[N];
int aa[N][N];
int bt[(1<<21)];
void solve(){
    int n;cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
            a[i][j]=(a[i][j]*binpow(10000,mod-2))%mod;
            aa[i][j]=binpow(a[i][j],mod-2);
        }
    }
    for (int i=1;i<(1<<n);i++){
        for (int j=0;j<n;j++){
            if (i&(1<<j)){
                bt[i]=j;
                break;
            }
        }
    }
    for (int i=0;i<n;i++){
        c[i]=1;
        for (int j=0;j<n;j++){
            c[i]=(c[i]*a[j][i])%mod;
        }
    }
    for (int i=0;i<n;i++){
        r[i][0]=1;
        for (int mask=1;mask<(1<<n);mask++){
            r[i][mask]=r[i][mask^(1<<bt[mask])]*a[i][bt[mask]]%mod;
        }
    }
    int res=0;
    for (int d1=0;d1<2;d1++){
        for (int d2=0;d2<2;d2++){
            for (int mask=0;mask<(1<<n);mask++){
                int mult=1;
                for (int i=0;i<n;i++){
                    if (mask&(1<<i)) mult*=c[i],mult%=mod;
                }
                for (int i=0;i<n;i++) mult1[i]=r[i][(1<<n)-mask-1];
                if (d1){
                    for (int i=0;i<n;i++){
                        if (mask&(1<<i)) continue;
                        mult=(mult*a[i][i])%mod;
                        mult1[i]=(mult1[i]*aa[i][i])%mod;
                    }
                }
                if (d2){
                    for (int i=0;i<n;i++){
                        if (mask&(1<<i)) continue;
                        if (d1 && i==n-i-1) continue;
                        mult=(mult*a[n-1-i][i])%mod;
                        mult1[n-1-i]=(mult1[n-1-i]*aa[n-1-i][i])%mod;
                    }
                }


                for (int i=0;i<n;i++) mult=(mult*(mod+1-mult1[i]))%mod;

                if ((d1+d2+__builtin_popcount(mask))%2){
                    res+=mult;
                } else {
                    res+=mod-mult;
                }
                res%=mod;
            }
        }
    }
    cout<<(res+1)%mod<<endl;

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
3
1000 2000 3000
4000 5000 6000
7000 8000 9000
**/