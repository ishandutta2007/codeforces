#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
    fast;
    
    int n;
    cin >> n;
    
    vector<pair< pair<int,char> ,string> > vowelcnt(n);
    
    f(i,n) cin >> vowelcnt[i].S;
    
    map<char,int> mm;
    mm['a']=1;
    mm['e']=1;
    mm['i']=1;
    mm['o']=1;
    mm['u']=1;
    
    f(i,n) 
    {
        vowelcnt[i].F.F=0;
        
        for(auto x : vowelcnt[i].S) 
            if(mm.find(x)!=mm.end()) 
                 { 
                   vowelcnt[i].F.F++; 
                   vowelcnt[i].F.S = x; 
                 }
    }   
        
    sort(vowelcnt.begin(),vowelcnt.end());
    
    int same = 0;
    int last = 0;
    int temp = 0;
    
    f(i,n)
    {
        if(last != vowelcnt[i].F.F)
        {
         same+=temp/2;   
         last = vowelcnt[i].F.F;
         temp = 1;   
        }
        else temp++;
    }
    
    same+=temp/2;
    
    int need = same/2;
    
    //need is the number of pairs needed atmost which have same lastvowel and 
    //count is also same
    
    vector<pair<string,string>> ans;
    vector<bool> vis(n+1,0);
    
    f(i,n-1)
    {
        if(need == 0 ) break;
        
        if(vis[i]) continue;
        
       if(vowelcnt[i].F == vowelcnt[i+1].F) 
       {
           ans.pb({vowelcnt[i].S,vowelcnt[i+1].S});
           vis[i] = 1;
           vis[i+1] = 1;
           need--;
       }
    }
    
    last = -1;
    int lastcnt = -1;
    int kp = 0;
    
    cout << ans.size() << "\n";
    
    f(i,n)
    {
      if(kp==ans.size()) break;
        
      if(vis[i]) continue;  
        
      if(lastcnt == vowelcnt[i].F.F)
      {
        cout << vowelcnt[last].S << " " << ans[kp].F << "\n";  
        cout << vowelcnt[i].S << " " <<  ans[kp++].S << "\n";
          
        lastcnt = last = -1;  
      }
      else 
      {
       last = i;   
       lastcnt = vowelcnt[i].F.F;   
      }
        
        
    }
    
    
}