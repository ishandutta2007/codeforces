#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

void solve()
{
  int n;
  cin >> n;
    
  string s;
  cin >> s;
    
  int cn1=0,cn2=0,sum1=0,sum2=0;
    
  f(i,n/2)
    if(s[i] == '?') cn1++; else sum1+=(s[i]-'0');   
  
  for(int i=n/2;i<n;i++)
    if(s[i] == '?') cn2++; else sum2+=(s[i]-'0');   
   
   if(cn1 > cn2) swap(cn1,cn2),swap(sum1,sum2);
    
    cn2-=cn1;
    cn1 = 0;
    cn2/=2;
    
   if(sum1 - sum2 == (9*cn2))  cout << "Bicarp";   
   else cout << "Monocarp";
   
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}