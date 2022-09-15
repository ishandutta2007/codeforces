#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    ll ans=2ll;
    ll cur1=1ll;
    ll cur2=1ll;

    for (int i=1;i<s.size();i++) {
         if (s[i]==s[i-1]) cur1++;
         else break;

    }
    for (int i=s.size()-2;i>=0;i--){
        if (s[i]==s[i+1])cur2++;
        else break;
    }
  //  cout<<cur1<<" "<<cur2<<endl;
    if (s[0]!=s[s.size()-1]){
        cout<<(cur1+cur2+1ll)%998244353;
    } else {
        cout<<((cur1+1ll)*(cur2+1ll))%998244353;
    }
    return 0;
}