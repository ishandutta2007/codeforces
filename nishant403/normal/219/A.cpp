#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
 fast;
 int k;
 string s;
    int c[26]={0};
    
  cin >> k;
  cin >> s;
    
   for(auto x : s) c[x-'a']++; 

for(int i=0;i<26;i++)
{
    if(c[i]%k!=0) {cout << -1; return 0;}
    else c[i]/=k;
}
    
    
for(int i=0;i<k;i++)
  for(int j=0;j<26;j++)  
   for(int z=0;z<c[j];z++) cout << (char)('a'+j);
    
    
}