
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int a[N];
void solve(){
    int x;cin>>x;
    ll res=-1ll;
    for (int mask=0;mask<(1<<9);mask++){
        int sum=0;
        ll num=0ll;
        for (int i=0;i<9;i++){
            if (mask&(1<<i)) sum+=i+1,num=num*10l+i+1ll;
        }
        if (sum==x){
            if (res==-1) res=num;
            res=min(res,num);
        }
    }
    cout<<res<<endl;

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
//3 1 5 4 2 2
//3 1 1