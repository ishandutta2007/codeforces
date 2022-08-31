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
    
f(i,n)    
{
    
 if(s[i]!='o' || i>n-3) cout << s[i];
 else
 {
  int flag = 1;   
 
  if(s[i+1]=='g' && s[i+2]=='o')
  {
   while(i<n-1 && s[i+1]=='g' && s[i+2]=='o') i+=2;
   cout << "***";   
  }
  else cout << s[i];   
    
 }
   
}
    
}

signed main()
{
    fast;
    solve();
}