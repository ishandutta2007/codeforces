#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int long long
using namespace std;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    string t="";
    int cnt=0;
    for (int i=0;i+1<s.size();i+=2){
        if (s[i]!=s[i+1])continue;
        if (s[i]=='a') s[i+1]='b';
        else s[i+1]='a';
        cnt++;
    }
    cout<<cnt<<endl;
    cout<<s<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;tt=1;
    while (tt--){
        solve();
    }
    return 0;
}