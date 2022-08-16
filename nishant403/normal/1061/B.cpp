#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<long> 

int main()
{
 fast;   
 ll n,k,i,h,j,m,ans=0;
 string s;
    
 cin >> n >> m;
 map<ll,ll> a;
    f(i,n) {  cin >> h; a[h]++; ans+=h;}
  
    a[0]++;   
   
 vector<ll> height;
 vector<ll> weight;
    
   for(auto x : a) height.push_back(x.first);
   for(auto x : a) weight.push_back(x.second);
    
   ll hd = height[height.size() - 1];
    
   for(i=height.size()-1;i>0;i--)
   {
    ll m = max(weight[i],hd-height[i-1]);
    ans-=m;
    hd-=m;   
   }
    
    cout << ans;
}