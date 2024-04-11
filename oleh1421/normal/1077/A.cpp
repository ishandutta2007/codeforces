#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
typedef long long ll;
using namespace std;

bool is_c(ll a){
   ll x=sqrt(a);
   return (x*x==a);
}
int main()
{
   ll a,b,k,t;
   cin>>t;
   vector<ll>ans;
   while (t--){
       cin>>a>>b>>k;
       ans.push_back((a-b)*(k/2)+a*(k%2));
   }
   for (int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
   return 0;
}