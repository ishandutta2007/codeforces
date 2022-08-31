#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

char rem(char a,char b)
{
  if(a>b) swap(a,b);  
  if(a=='a'  && b=='b') return 'c';
  if(a=='a'  && b=='c') return 'b';
  if(a=='b'  && b=='c') return 'a';
    assert(1==0);
    return 'b';
}    

void solve()
{ 
  int n; cin >> n;
    
  string s,t;
    cin >> s ;
    cin >> t;
    
    cout << "YES\n";
   
    if(t[0] == t[1]) swap(s,t);
    
    if(s[0] == s[1])
    {
      if(t[0] == t[1])
      {
        f(i,n) cout << "abc";   return;
      }
      else
      {
        if(t[0] == s[0] || t[1] == s[0])
        {  
            char c=rem(t[0],t[1]);
             if(t[0] == s[0]) f(i,n) cout << t[1];
             else f(i,n) cout<< t[0];
            
             f(i,n) cout << c << s[0];
        }
        else
        {
          f(i,n) cout << t[0] << s[0];
          f(i,n) cout << t[1];
          return;  
        }
      } 
    }
    else
    { 
      if(s[0] == t[1] && t[0] == s[1])   
      { 
       char c= rem(s[0],s[1]);
          f(i,n) cout << s[0] << c;
          f(i,n) cout << s[1];
          return;
      } 
      else if(s[0] == t[0] && s[1] == t[1])
      { 
          char c = rem(s[0],s[1]);
          f(i,n) cout << s[0] << c << s[1];
          return;
      }
      else
      {
          char c= rem(s[0],s[1]);
          
          if(s[0] == t[0])
          {
           f(i,n) cout<< s[1];
           f(i,n) cout<< t[1];
           f(i,n) cout<< s[0];   
          }
          else if(s[0] == t[1])
          {
           f(i,n) cout<< t[0];
           f(i,n) cout<< s[1];
           f(i,n) cout<< s[0];      
          }
          else if(s[1] == t[0])
          {
           f(i,n) cout<< t[1];
           f(i,n) cout<< t[0];
           f(i,n) cout<< s[0];      
          }
          else
          {
           f(i,n) cout<< t[1];
           f(i,n) cout<< s[0];
           f(i,n) cout<< t[0];      
          }
          
      }
        
    }
    
    
}

int main()
{
    solve();
}