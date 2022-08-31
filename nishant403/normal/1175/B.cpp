#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define f(i,n) for(int i=0;i<n;i++)
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>

int val = (1LL<<32) - 1;
    

void chh(int n)
{
    if(n<0 || n > val) {cout << "OVERFLOW!!!"; exit(0); }  
}
   
   
signed main()
{    
    Fast;
    
    int l;
    string s;
   
    cin >> l;
    
    stack<pii> sys;
    
    int k;
    int gg = 0;
    
    while(l--)
    {
       cin >> s; 
         
        if(s=="for")
        {
            cin >> k;
            sys.push({k,0});   
        }
        
        else if(s=="add")
        {
          if(sys.empty()) 
          { 
              gg++;
             chh(gg);  
          }
            
          else 
          {
             auto y = sys.top(); 
             sys.pop();
             y.S++;
            
             chh(y.S);
              
             sys.push(y); 
          }
            
            
        }
        
        else
        {
         auto h = sys.top();
         sys.pop();
         
         if(!sys.empty())
         {
         auto kk = sys.top();   
          sys.pop();  
          
           chh(h.F*h.S);
              
          kk.S+=(h.F*h.S); 
             
          chh(kk.S);   
             
          sys.push(kk);
             
         }  
         else
         {
          gg+=(h.F*h.S);
             
          chh(h.F*h.S);
          chh(gg);
         }
                
        }
        
    }
    
    chh(gg);
    
    cout << gg;
}