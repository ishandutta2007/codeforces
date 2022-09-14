#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int x;cin>>x;
            if ((i+j)%2){
                if (x%2) cout<<x<<" ";
                else cout<<x+1<<" ";
            } else {
                if (x%2) cout<<x+1<<" ";
                else cout<<x<<" ";
            }
        }
        cout<<endl;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}