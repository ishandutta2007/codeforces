#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int a,b,c;cin>>a>>b>>c;
        int res=0;
        for (int i=0;i<=min(a,b/2);i++){
            res=max(res,i*3+min(b-i*2,c/2)*3);
        }
        cout<<res<<endl;
    }
    return 0;
}