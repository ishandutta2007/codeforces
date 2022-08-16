#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
vector<int> graph[100001];
vector<bool> vis(100001,0);
map<pair<int,int>,int> ed;



int dfs(int x)
{
vis[x]=1;
    
int ans = 1;
    
 for(auto z : graph[x])
 {
     if(!vis[z]) { ed[{x,z}]=dfs(z); ans+=ed[{x,z}]; }   
 }
    
 return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    set<int> intro,extro;
    map<int,int> bs;
    
    int w;
    
    for(int i=0;i<n;i++) { cin >> w; intro.insert(w); bs[w]=i+1;}
    
    string s;
    cin >> s;
    
    for(auto x : s)
    {
     int p=x-'0';   
        
        if(p==0) {int c=*intro.begin(); intro.erase(c); extro.insert(c); cout << bs[c] << " ";  }
        else { int c=*extro.rbegin(); extro.erase(c);  cout << bs[c] << " "; }
    }
    
}