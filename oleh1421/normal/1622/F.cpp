#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
mt19937_64 rnd(time(NULL));
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=1500010;
const ll mod=998244353;
int p[N];
vector<int>d[N];
ll a[N];
int ans[N];
int CNT=0;
int CUR=0;
void upd(int i,int x){
    CUR-=(ans[i]^ans[i+1]);
    if (i>1) CUR-=(ans[i-1]^ans[i]);
    for (int p:d[i]){
        CNT-=a[p];
        a[p]^=(ans[i]^x);
        CNT+=a[p];
    }
    ans[i]=x;
    CUR+=(ans[i]^ans[i+1]);
    if (i>1) CUR+=(ans[i-1]^ans[i]);
}
ll X[N];
void solve(){
    int n;cin>>n;
    for (int i=2;i<=n;i++) p[i]=i;
    for (int i=2;i<=n;i++){
        if (p[i]==i){
            for (int j=i*2;j<=n;j+=i) p[j]=i;
        }
    }
    d[1]={};
    for (int i=2;i<=n;i++){
        int cnt=0;
        int x=i;
        while (x%p[i]==0){
            cnt++;
            x/=p[i];
        }
        d[i]=d[x];
        if (cnt%2) d[i].push_back(p[i]);
    }
    if (n==1){
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }

    ll cnt=0;
    for (int i=n;i>=2;i-=2){
        for (int j:d[i]){
            cnt^=a[j]*X[j];
            a[j]^=1;
            cnt^=a[j]*X[j];
        }
    }
    for (int i=1;i<=n;i++) X[i]=1ll*rnd();
    while (true){
        cnt=0;
        for (int i=0;i<=n;i++) a[i]=0;
        for (int i=n;i>=2;i-=2){
            for (int j:d[i]){
                cnt^=a[j]*X[j];
                a[j]^=1;
                cnt^=a[j]*X[j];
            }
        }
        for (int i=1;i<=n;i++){
            for (int j:d[i]){
                cnt^=a[j]*X[j];
                a[j]^=1;
                cnt^=a[j]*X[j];
            }
            if (cnt==0){
                cout<<n-1<<endl;
                for (int j=1;j<=n;j++){
                    if (i!=j) cout<<j<<" ";
                }
                cout<<endl;
                return;
            }
        }
            map<ll,int>mp;

        cnt=0;
        for (int i=0;i<=n;i++) a[i]=0;
        for (int i=1;i<=n;i++){
            for (int j:d[i]){
                cnt^=a[j]*X[j];
                a[j]^=1;
                cnt^=a[j]*X[j];
            }
            if (mp.find(cnt)==mp.end()) mp[cnt]=i;
        }
        cnt=0;

        for (int i=0;i<=n;i++) a[i]=0;
        for (int i=n;i>=2;i-=2){
            for (int j:d[i]){
                cnt^=a[j]*X[j];
                a[j]^=1;
                cnt^=a[j]*X[j];
            }
        }
        for (int i=1;i<=n;i++){
            for (int j:d[i]){
                cnt^=a[j]*X[j];
                a[j]^=1;
                cnt^=a[j]*X[j];
            }
            if (mp.find(cnt)!=mp.end() && mp[cnt]<i){
                cout<<n-2<<endl;
                for (int j=1;j<=n;j++){
                    if (j!=mp[cnt] && j!=i) cout<<j<<" ";
                }
                cout<<endl;
                return;

            }
        }
        n--;
    }




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




**/