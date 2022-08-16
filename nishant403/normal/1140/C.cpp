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
 ll n,k,i,j,ans=0,sum=0;
 ll x,y;   
 string s;
    
 cin >> n >> k;
    
 vector<pll> input;
    
    f(i,n) {
        cin >> x >> y;
        input.pb({y,x});
    }
    
  sort(input.begin(),input.end() );
  priority_queue<ll> q;    
    
  for(i=n-1;i>=0;i--)
  {
   q.push(-input[i].S);
   sum+=input[i].S;  
      if(q.size() > k ) sum+=q.top(),q.pop(); 
  ans=max(ans,sum*input[i].F);  
 
  }
    cout << ans;
}