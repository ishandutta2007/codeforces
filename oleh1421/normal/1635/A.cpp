#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=300010;
const ll mod=1000000007;
const ll inf=4e18;
const int L=20;
int a[N];
vector<vector<int> >ans;
void go(int x,int y,int z){
    a[x]=a[y]-a[z];
    ans.push_back({x,y,z});
}
void solve(){
    int n;cin>>n;
    int ans=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        ans|=x;
    }
    cout<<ans<<endl;


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