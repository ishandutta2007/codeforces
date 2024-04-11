#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=55;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    string s1=s;
    reverse(s1.begin(),s1.end());
    int cnt=0;
    for (auto cur:s){
        if (cur=='1') cnt++;
    }
    if (cnt==n) cout<<"DRAW\n";
    else if (s==s1 && (cnt==n-1 || n%2==0 || s[n/2]=='1')) cout<<"BOB\n";
    else cout<<"ALICE\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}