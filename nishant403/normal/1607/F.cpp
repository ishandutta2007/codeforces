#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 2000 + 5;
const int NN = 4e6 + 10;

int n,m;
string s[N];
int p[NN],res[NN];

void solve()
{
   cin >> n >> m;
   f(i,n) cin >> s[i];
   
   f(i,n*m + 1) res[i] = 0;
   
   f(i,n) f(j,m)
   {
       int u = i;
       int v = j;

       if(s[i][j] == 'D') u++;
       else if(s[i][j] == 'U') u--;
       else if(s[i][j] == 'L') v--;
       else v++;

       if(u < 0 || v < 0 || u >= n || v >= m) res[i*m + j] = 1;
       else p[i*m + j] = u*m + v;
   }
  
   f(i,n*m)
   {
       if(res[i] > 0) continue;
       
       int nd = i;
       
       vector<int> go;
       
       while(res[nd] == 0)
       {
           res[nd] = -1;
           go.push_back(nd);
           nd = p[nd];
       }
       
       reverse(all(go));
       
       if(res[nd] == -1)
       {
           int cyc_len = 1;
           int tmp = p[nd];
           
           while(tmp != nd)
           {
               cyc_len++;
               tmp = p[tmp];
           }
           
           res[nd] = cyc_len;
           tmp = p[nd];
           
           while(tmp != nd)
           {
               res[tmp] = cyc_len;
               tmp = p[tmp];
           }
       }
       
       int lst = res[nd];
       
       f(j,go.size()) 
           if(res[go[j]] == -1) res[go[j]] = ++lst;
   }
   
   pair<int,pii> ans = {res[0],{0,0}};
    
   f(i,n) f(j,m) 
       ans = max(ans,{res[i*m + j],{i,j}});
    
   cout << ans.S.F + 1 << ' ' << ans.S.S + 1 << ' ' << ans.F << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}