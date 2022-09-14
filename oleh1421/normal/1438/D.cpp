#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300100;
int a[N];
vector<vector<int> >ans;
void go(int i,int j,int t){
    int xr=a[i]^a[j]^a[t];
    a[i]=a[j]=a[t]=xr;
    ans.push_back({i,j,t});
}
void solve(){
    int n;cin>>n;
    int Xr=0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        Xr^=a[i];
    }
    if (n%2==0 && Xr){
        cout<<"NO\n";
        return;
    }
    for (int i=1;i+2<=n;i+=2){
        go(i,i+1,i+2);
    }
    for (int i=1;i+2<=n;i+=2){
        go(i,i+1,n);
    }
//    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
//    cout<<endl;
    cout<<"YES\n";
    cout<<ans.size()<<endl;
    for (auto v:ans){
        for (int i:v) cout<<i<<" ";
        cout<<endl;
    }



}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}