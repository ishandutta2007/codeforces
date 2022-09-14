#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=15010;
const ll mod=998244353;
int a[12][N];
int mult[N];
int p[N];
int ans[N];
vector<int>g[N];
int x[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=0;i<n;i++) cin>>x[i];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            char c;cin>>c;
            a[i][j]=(c-'0');
        }
    }
    int res=-1;
    for (int mask=0;mask<(1<<n);mask++){
        for (int i=0;i<m;i++) mult[i]=0;
        for (int i=0;i<=2*n;i++) g[i].clear();
        int cur=0;
        for (int i=0;i<n;i++){
            if (mask&(1<<i)){
                cur+=x[i];
                for (int j=0;j<m;j++) mult[j]-=a[i][j];
            } else {
                cur-=x[i];
                for (int j=0;j<m;j++) mult[j]+=a[i][j];
            }
        }
        for (int j=0;j<m;j++) g[mult[j]+n].push_back(j);
        int cnt=0;
        for (int j=0;j<=n*2;j++){
            for (int x:g[j]) p[x]=++cnt;
        }
        for (int j=0;j<m;j++) cur+=mult[j]*p[j];
//        if (mask==9) {
//            cout<<"AAA "<<cur<<endl;
//            for (int j=0;j<m;j++) cout<<mult[j]<<" ";
//            cout<<endl;
//        }
        if (cur>res){
            res=cur;
            for (int j=0;j<m;j++) ans[j]=p[j];
        }
    }
    for (int i=0;i<m;i++) cout<<ans[i]<<" ";
    cout<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**




**/