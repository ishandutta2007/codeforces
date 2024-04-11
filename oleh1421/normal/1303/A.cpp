#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
void solve(){
    string s;cin>>s;
    int l=-1;
    int r=-2;
    for (int i=0;i<s.size();i++){
        if (s[i]=='1'){
            if (l<0) l=i;
            r=i;
        }
    }
    int cnt=0;
    for (int i=l;i<=r;i++) cnt+=(s[i]=='0');
    cout<<cnt<<endl;
}

int32_t main()
{
//    freopen("repair.in","r",stdin);
//    freopen("repair.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}