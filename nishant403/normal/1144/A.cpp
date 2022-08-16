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
 ll n,k,i,j,a=0;
 string s;
    
cin >> n;
    
    f(i,n)
    {
        cin >> s;
        int c[26]={0};
        int flag=true;
        
       f(j,s.length() )
       {
       c[s[j]-'a']++;
       if(c[s[j]-'a'] > 1 ) flag = false;                
       }
        
       sort(s.begin(),s.end() );
          
          if(flag) 
       f(j,s.length() - 1)
          {
           if(s[j+1]-s[j] != 1) flag=false;
          }  
        
          if(flag) cout << "Yes\n";
                 else cout << "No\n";
    }
    
    
    
}