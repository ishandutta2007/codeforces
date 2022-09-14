#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2010;
const int inf=1000000001;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int cnt=0;
    for (int i=1;i<n;i++){
        cnt+=(s[i]==s[i-1]);
    }
    cout<<(cnt+1)/2<<endl;
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