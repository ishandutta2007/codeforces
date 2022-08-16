#include <bits/stdc++.h>
using namespace std;

vector<int> graph[26],vis(26,0);
map<int,char> m1;
map<char,int> m2;

#define f(i,n) for(int i=0;i<n;i++)

string ss="";

void dfs(int node,int p)
{
  vis[node]=1;
      
    for(auto x : graph[node])
    {
     if(vis[x]==0)
     {
      dfs(x,node);   
     }
     else if(vis[x]==1 ) { cout << "Impossible"; exit(0); } 
    }
    
    ss+=('a' +node);
    vis[node]=2;
}

int main()
{
    
 int n;
   cin >> n;
    
 vector<string> s(n);
    
    f(i,n) cin >> s[i];
    
    
  f(i,n-1)
  {
   int n1=s[i].length();
   int n2=s[i+1].length();
   int c=0;   
   
   while(s[i][c]==s[i+1][c] && c<min(n1,n2) ) c++;
      
      if(c==min(n1,n2) ) { if(n1>n2) { cout << "Impossible"; return 0; }
                          else ; }
      else graph[s[i][c]-'a'].push_back(s[i+1][c]-'a'); 
  }
    
    f(i,26) if(vis[i] == 0 ) dfs(i,-1);
        
     reverse(ss.begin(),ss.end());   
        
    cout << ss;
}