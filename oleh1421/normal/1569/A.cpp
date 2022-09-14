#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=100010;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    for (int i=1;i<s.size();i++){
        if (s[i]!=s[i-1]){
            cout<<i<<" "<<i+1<<endl;
            return;
        }
    }
    cout<<"-1 -1\n";
}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}