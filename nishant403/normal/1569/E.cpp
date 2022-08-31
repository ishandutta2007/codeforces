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
#define all(x) x.begin(),x.end()

//Keep things simple and clean, dont make it complicated :(
//Idea : games from first half and second half can be combined easily 

const int MOD = 998244353;

int k,A,h,n;
int pw[100];

vector<int> positions;

map<int,int> mp[50];

//first[i].F = tournament score from first half people when i comes out as winner
//first[i].S = mask of decisions 

int ans[50];

//returns score and winner when  players from l to r win according to mask
pair<int,int> eval(int mask,int l,int r)
{
    queue<int> q;
    for(int i=l;i<=r;i++) q.push(i);
    
    int score = 0;
    
    f(i,(n/2) - 1)
    {
        int p1 = q.front(); q.pop();
        int p2 = q.front(); q.pop();
        
        if((mask >> i) & 1) swap(p1,p2);
        
        q.push(p1);
        score += p2*pw[positions[i]];
        score %= MOD;

        ans[p2] = positions[i];
    }
    
    return {score,q.front()};
}

void solve()
{
   cin >> k >> A >> h;
    
   n = (1LL<<k);
    
   f(i,k-1)
       f(j,(1LL<<(k-i-2))) positions.pb((1LL<<(k-i-1)) + 1);
    
   pw[0] = 1;
   for(int i=1;i<100;i++) pw[i] = (pw[i-1]*A)%MOD;
    
   for(int i=0;i<(1LL<<((n/2) - 1));i++)
   {
       auto temp = eval(i,1,n/2);
       mp[temp.second][temp.first] = i;
   }
   
   for(int i=0;i<(1LL<<((n/2) - 1));i++)
   {
       auto temp = eval(i,(n/2) + 1,n);
       
       //winner from the first half 
       for(int j=1;j<=n/2;j++)
       {
           //final winner from first or second half
           for(int v=0;v<=1;v++)
           {
               int need = h - temp.F - temp.S*pw[v + 1] - j*pw[2 - v];
               need %= MOD;
               if(need < 0) need += MOD;
               
               if(mp[j].find(need) != mp[j].end())
               {
                   eval(mp[j][need],1,n/2);
                   ans[temp.second] = v + 1;
                   ans[j] = 2 - v;
                   
                   for(int i=1;i<=n;i++) cout << ans[i] << ' ';
                   
                   return;
               }
           }
       }
   }
    
   cout << -1;
}

signed main()
{
    fast;
    solve();
}