#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1010;
void solve(){
    int x,y;cin>>x>>y;
    cout<<min(x,y)*2+max(0,abs(x-y)*2-1)<<endl;
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