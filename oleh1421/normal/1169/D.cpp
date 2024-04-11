#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
bool ok(int l,int r){
     for (int x=l;x<=r;x++){
        for (int k=1;x+k+k<=r;k++){
            if (s[x]==s[x+k] && s[x+k]==s[x+k+k]) return false;
        }
     }
     return true;
}
int main()
{
    cin>>s;
    ll cnt=0ll;
    ll n=(int)s.size()*1ll;
    for (int l=0;l<n;l++){
        for (int r=l;r<n;r++){
            if (ok(l,r)) cnt++;
            else break;
        }
    }
    cout<<n*(n+1ll)/2ll-cnt;
    return 0;
}