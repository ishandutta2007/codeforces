#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000100;
const ll mod=998244353;
int cnt[N];
ll ans[N];
int dsu[N];
int ind[N];
bool used[N];
int get(int x){
    if (dsu[x]==x) return x;
    return dsu[x]=get(dsu[x]);
}
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=0;i<=n;i++) cnt[i]=0;
    for (int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    sort(a+1,a+n+1);
    int MX=0;
    for (int i=1;i<=n;i++){
        if (a[i]>i-1) break;
        MX=i;
    }
    for (int i=MX+1;i<=n;i++) ans[i]=-1;
    for (int i=0;i<=n;i++) dsu[i]=i,used[i]=false;
    dsu[0]=0;
    ind[0]=0;
    ans[0]=0;
    used[0]=true;
    for (int i=1;i<=MX;i++){
        int r=upper_bound(a+1,a+n+1,i-1)-a-1;
        if (used[r]){
            ans[i]=ans[i-1]+a[(get(r)-1)];
            dsu[get(r)]=get(r)-1;
            used[get(r)]=true;
            if (used[get(r)-1]) dsu[get(r)]=get(r)-1;
        } else {
            ans[i]=ans[i-1]+a[r];
            used[r]=true;
            if (used[r-1]) dsu[r]=r-1;
        }
    }
    for (int i=0;i<=MX;i++){
        ans[i]=(i-1ll)*i/2ll-ans[i]+cnt[i];
    }

    for (int i=0;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//A[j] - >
//(a+b1)%M+(b2+c)%M<(a+c)%M