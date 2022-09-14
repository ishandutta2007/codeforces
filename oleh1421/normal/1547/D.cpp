//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=400010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int X=0;
    vector<int>ans;
    for (int i=1;i<=n;i++){
        int Y=0;
        for (int j=29;j>=0;j--){
            if ((X&(1<<j)) && ((a[i]&(1<<j))==0)){
                Y^=(1<<j);
            }
        }
        X=a[i]^Y;
        ans.push_back(Y);
    }
    for (int i:ans) cout<<i<<" ";
    cout<<endl;



}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
4 4
1 2
2 3
1 4
4 3
**/