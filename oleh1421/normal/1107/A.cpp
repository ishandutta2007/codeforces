#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll fi[200002];
ll dp[200002];
ll a[200002];
int main()
{
    int q;cin>>q;
    while (q--){
        string s;cin>>s>>s;
        if (s.size()==2 && s[0]>=s[1]) cout<<"NO"<<endl;
        else {
        cout<<"YES"<<endl<<2<<endl<<s[0]<<" ";
        for (int i=1;i<s.size();i++) cout<<s[i];
        cout<<endl;
        }
    }
    return 0;
}