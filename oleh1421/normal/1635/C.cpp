#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=300010;
const ll mod=1000000007;
const ll inf=4e18;
const int L=20;
ll a[N];
vector<vector<int> >ans;
void go(int x,int y,int z){
    a[x]=a[y]-a[z];
    ans.push_back({x,y,z});
}
void solve(){
    ans.clear();
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (a[n-1]>a[n]){
        cout<<-1<<endl;
        return;
    }
    if (a[n]>=0){
        for (int i=n-2;i>=1;i--){
            go(i,i+1,n);
        }
    } else {
        if (!is_sorted(a+1,a+n+1)){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans){
        for (int i:cur) cout<<i<<" ";
        cout<<endl;
    }




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
12837720
**/