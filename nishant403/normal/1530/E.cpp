#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

void solve()
{
   string s;
   cin >> s;
    
   int n = s.length();
    
   vi fre(26,0);
   for(auto x : s) fre[x-'a']++;
   
   vector<pii> mp;
   f(i,26) if(fre[i] > 0) mp.pb({fre[i],i});
       
   //find first character having frequency 1 , that guarantees f to be 0.
   int cc = -1; 
    
   f(i,26) if(fre[i] == 1)
   {
       cc = i;
       break;
   }
    
   if(cc != -1)
   {
       cout << (char)(cc + 'a');
       fre[cc]--;
       
       f(i,26) f(j,fre[i]) cout << (char)(i + 'a');
       cout << '\n';
       return;
   }
   
   //use case work  
   if(mp.size() == 1) cout << s << '\n';
   else if(n - mp[0].F >= mp[0].F - 2)
   {
       //aa + X + a + X' + a + ...
       mp[0].F--;
       cout << (char)('a' + mp[0].S);
       
       string oth;
       for(int i=1;i<mp.size();i++) 
       f(j,mp[i].F) oth += ('a' + mp[i].S);
       reverse(all(oth));
       
       while(mp[0].F > 0)
       {
           mp[0].F--;
           cout << (char)('a' + mp[0].S);
           
           if(oth.size() > 0)
           {
               cout << oth.back();
               oth.pop_back();
           }
       }
       
       reverse(all(oth));
       cout << oth << '\n';
   }
   else if(mp.size() == 2)
   {
       //a + bbb... + aaa...
       mp[0].F--;
       cout << (char)('a' + mp[0].S);
       
       while(mp[1].F > 0)
       {
           mp[1].F--;
           cout << (char)('a' + mp[1].S);
       }
       
       while(mp[0].F > 0)
       {
           mp[0].F--;
           cout << (char)('a' + mp[0].S);
       }
       
       cout << '\n';
   }
   else
   {
       //a + b + aaa... + c + remaining 
       mp[0].F--;
       cout << (char)('a' + mp[0].S);
     
       mp[1].F--;
       cout << (char)('a' + mp[1].S);
  
       while(mp[0].F > 0)
       {
           mp[0].F--;
           cout << (char)('a' + mp[0].S);
       }
       
       mp[2].F--;
       cout << (char)('a' + mp[2].S);
       
       for(auto x : mp)
       {
           f(j,x.F) cout << (char)('a' + x.S);
       }
       
       cout << '\n';
   }
}

signed main()
{   
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}