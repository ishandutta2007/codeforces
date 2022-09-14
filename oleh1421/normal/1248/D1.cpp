#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
//#define inf 1000000000000000001ll
const long long mod=1000000007ll;
ll binpow(ll a,ll b){
    if (b==0ll) return 1ll;
    if (b%2ll) return (a*binpow(a,b-1ll))%mod;
    else return binpow((a*a)%mod,b/2ll);
}
int a[200001];
int s[200001];
int x[200001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        if (c=='(') a[i]=1;
        else a[i]=-1;
        s[i]=s[i-1]+a[i];
    }
    if (s[n]!=0){
        cout<<0<<endl<<"1 1";
        return 0;
    }
    int res=-1;
    int l=-1;
    int r=-1;

    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            swap(a[i],a[j]);
            int cnt=0;
            s[0]=0;

            for (int t=1;t<=n;t++) s[t]=s[t-1]+a[t];
            x[n+1]=0;
            for (int t=n;t>=1;t--) x[t]=min(x[t+1],s[t]);
            int minx=0;
            for (int t=1;t<=n;t++){
                minx=min(minx,s[t]);
                if (s[n]-s[t]+minx>=0 && x[t+1]-s[t]>=0) cnt++;
            }
            if (cnt>res){
                res=cnt;
                l=i;
                r=j;
            }
            swap(a[i],a[j]);
        }
    }
    cout<<res<<endl<<l<<" "<<r;
    return 0;
}
/*

*/