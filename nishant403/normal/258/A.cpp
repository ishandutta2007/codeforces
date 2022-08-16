#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


signed main()
{
Fast;    
    
  string s;
    getline(cin,s);
    
    int flag = 0;
    
   for(int i=0;i<s.length();i++)
   {
    if(s[i]=='0' || i==s.length()-1) 
    {
     i++;
        
        for(;i<s.length();i++)
            cout << s[i];
        return 0;
    }
     cout << s[i];  
   }
    
    
}