#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int32_t main() {
   ll a,b,c;cin>>a>>b>>c;
   ll res=2ll*c+min(a,b)*2ll+min(max(a,b)-min(a,b),1ll);
   cout<<res;
   return 0;
}