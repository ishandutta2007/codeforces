#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000007ll;

void solve(){
    int a,b,c;cin>>a>>b>>c;
    if (!b){
        if (a){
            for (int i=0;i<=a;++i) cout<<0;
            cout<<endl;
        } else{
            for (int i=0;i<=c;i++) cout<<1;
            cout<<endl;
        }
        return;
    }
    for (int i=0;i<=a;i++) cout<<0;
    for (int i=0;i<=c;i++) cout<<1;
    for (int i=0;i+1<b;i++) cout<<(i%2);
    cout<<endl;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}