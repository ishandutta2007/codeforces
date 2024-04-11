#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
///#define int long long
#define endl '\n'

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int a,b,c,d,k;cin>>a>>b>>c>>d>>k;
        int x=(a+c-1)/c;
        int y=(b+d-1)/d;
        if (x+y<=k) cout<<x<<" "<<y<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}