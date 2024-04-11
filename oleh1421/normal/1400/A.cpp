
#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    string res="";
    for (int i=0;i<n;i++) res+=s[n-1];
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}