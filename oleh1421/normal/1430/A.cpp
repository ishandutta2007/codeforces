#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
void solve(){
    int n;cin>>n;
    if (n<3 || n==4){
        cout<<-1<<endl;
        return;
    }
    if (n==7){
        cout<<"0 0 1\n";
        return;
    }
    for (int i=0;i*5<=n;i++){
        if ((n-i*5)%3==0){
            cout<<(n-i*5)/3<<" "<<i<<" "<<0<<endl;
            return;
        }
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