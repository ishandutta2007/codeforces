//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=501010;
const int L=20;
const ll mod=1000000007;
const int inf=1e9;
int p[N];
struct BITS{
    int t[N];
    int n;
    void clr(){
        for (int i=0;i<=n;i++) t[i]=0;
    }
    void upd(int pos,int x){
        for (;pos<=n;pos|=pos+1) t[pos]+=x;
    }
    int get(int pos){
        int sum=0;
        for (;pos>=0;pos&=pos+1,pos--) sum+=t[pos];
        return sum;
    }
};
BITS T;
ll val[N];
ll ans[N];
bool used[N];
int ind[N];
void solve(int Case){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i],used[i]=false;
    T.n=n;
    T.clr();
    ans[0]=0ll;
    for (int i=1;i<=n;i++){
        val[i]=i-1-T.get(p[i]-1);
        T.upd(p[i],1);
        ans[0]+=val[i];
        val[i]=2*(p[i]-1)-(i-1);
        ans[i]=val[i];
    }
    sort(ans+1,ans+n+1);
    for (int i=1;i<=n;i++) ans[i]-=i-1;
    for (int i=1;i<=n;i++) ans[i]+=ans[i-1];
    for (int i=0;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;


}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}