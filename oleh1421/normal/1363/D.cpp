//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=1010;
vector<int>g[N];
int n,k;
bool used[N];
int qq(vector<int>x){
    for (int i=0;i<=n;i++) used[i]=false;
    for (auto a:x) used[a]=true;
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (!used[i]) v.push_back(i);
    }
    cout<<"? "<<v.size()<<" ";
    for (auto i:v) cout<<i<<" ";
    cout<<endl;
    int cur;cin>>cur;
    return cur;
}
void solve(){
    cin>>n>>k;
    for (int i=0;i<=k+1;i++) g[i].clear();
    for (int i=1;i<=k;i++){
        int c;cin>>c;
        for (int j=1;j<=c;j++){
            int x;cin>>x;
            g[i].push_back(x);
        }
    }
    cout<<"? "<<n<<" ";
    for (int i=1;i<=n;i++) cout<<i<<" ";
    cout<<endl;
    int tot;cin>>tot;
    int mx=n;
    for (int i=9;i>=0;i--){
        if (mx-(1<<i)<1) continue;
        mx-=(1<<i);
        cout<<"? "<<mx<<" ";
//        cout<<
        for (int j=1;j<=mx;j++) cout<<j<<" ";
        cout<<endl;
        int cur;cin>>cur;
        if (cur<tot) mx+=(1<<i);
    }
    vector<int>ans;
    for (int i=1;i<=k;i++){
        bool ok=true;
        for (auto x:g[i]){
            if (x==mx) {
                ok=false;
                break;
            }
        }
        if (ok) ans.push_back(tot);
        else {
            ans.push_back(qq(g[i]));
        }
    }
    cout<<"! ";
    for (auto i:ans) cout<<i<<" ";
    cout<<endl;
    string verdict;cin>>verdict;

}
int main()
{
//    freopen("fuel.in","r",stdin);
//    freopen("fuel.out","w",stdout);
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}