#include <bits/stdc++.h>
#define hash yugyhiui
typedef long long ll;
using namespace std;
const long long mod=991987651ll;
void solve(){
   int n,a,b,s;cin>>a>>b>>n>>s;
   int c=min(a,s/n);
   s-=c*n;
   if (s<=b) cout<<"YES\n";
   else cout<<"NO\n";


}
int main()
{
   int tt;cin>>tt;
   while (tt--){
      solve();
   }
   return 0;
}