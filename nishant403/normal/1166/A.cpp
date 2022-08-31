#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pll pair<int,int>
#define vl vector<int>


signed main()
{
FAST;    
int n,i,j,k,m;
string s;
    
cin >> n;
int c[26]={0};    

 f(i,n)
{
 cin >> s;
 c[s[0]-'a']++;
    
}
    
int ans  = 0;
    
 f(i,26) 
 { int x = c[i]/2;   
  
ans+=(x*(x-1))/2;
ans+=((c[i]-x)*(c[i]-x-1) )/2;
 }
    cout << ans;
}