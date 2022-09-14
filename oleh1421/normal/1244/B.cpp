#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
///#define int long long
#define endl '\n'
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int n;cin>>n;
        string s;cin>>s;
        int l=-1;
        for (int i=0;i<n;i++){
            if (s[i]=='1'){
                l=i;
                break;
            }
        }
        int r=-1;
        //reverse(s.begin(),s.end());
        for (int i=n-1;i>=0;i--){
            if (s[i]=='1'){
                r=i;
                break;
            }
        }
        if (l==-1) cout<<n<<endl;
        else cout<<max(max({n-l,r+1})*2,n)<<endl;
    }
    return 0;
}