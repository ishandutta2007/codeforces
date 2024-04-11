
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000100;
int p[N];
vector<int>ans;
void go(int pref){
    ans.push_back(pref);
    reverse(p+1,p+pref+1);
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=n;i++){
        if (p[i]%2!=i%2){
            cout<<-1<<endl;
            return;
        }
    }

    for (int i=n;i>=3;i-=2){
        int a=-1,b=-1;
        for (int j=1;j<=i;j++){
            if (p[j]==i) b=j;
        }
        go(b);
        for (int j=1;j<=i;j++){
            if (p[j]==i-1) a=j;
        }
        go(a-1);
        go(a+1);
        go(3);
        go(i);
    }
//    cout<<"! ";
//    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
//    cout<<endl;
    cout<<ans.size()<<endl;
    for (int i:ans) cout<<i<<" ";
    cout<<endl;
    ans.clear();
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
//1 3 3 4
//0 1 2 3