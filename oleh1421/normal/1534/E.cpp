#include <bits/stdc++.h>

typedef long long ll;
//#define endl '\n'
using namespace std;
//#define int ll
const int N=500010;
const ll mod=1000000007;
bool used[N];
int d[N];
void solve(){
    int n,k;cin>>n>>k;
    if (k%2==0 && n%2){
        cout<<-1<<endl;
        return;
    }
    for (int i=1;i<=n;i++) d[i]=1;
    int sum=n;
    int mx=0;

    for (int it=1;sum%k>0 || mx>(sum/k);it++){
        int pos=it%n;
        if (!pos) pos=n;
        d[pos]+=2;
        mx=max(mx,d[pos]);
        sum+=2;
    }
    vector<int>v;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=d[i];j++) v.push_back(i);
    }
    int d=sum/k;
    int ans=0;
    for (int i=0;i<d;i++){
        vector<int>u;
        for (int j=0;j<k;j++){
            u.push_back(v[i+j*d]);
        }
        cout<<"? ";
        for (int i:u) cout<<i<<" ";
        cout<<endl;
        int x;cin>>x;
        ans^=x;
    }
    cout<<"! "<<ans<<endl;



}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/// 18 15
//1 2