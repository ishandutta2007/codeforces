
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int it=0;
    int l=1,r=n;
    while (l<=r){
        it++;
        if (it%2) cout<<a[l++];
        else cout<<a[r--];
        cout<<" ";
    }
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
//3 1 5 4 2 2
//3 1 1