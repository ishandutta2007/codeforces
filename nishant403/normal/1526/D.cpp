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

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 1e5 + 10;

string cc = "ABCD";
vector<int> pos[4];
int fre_s[N][4];
int fre_t[N][4];

int solve(string & s,string & t)
{
    int rr = 0;
    int n = s.length();
    
    f(i,n) f(j,4) fre_t[i][j] = 0;
    f(i,n) fre_t[i][t[i] - 'A'] = 1;
    f(i,n-1) f(j,4) fre_t[i+1][j] += fre_t[i][j];
    
    f(i,n) pos[t[i] - 'A'].pb(i);
    f(i,4) reverse(all(pos[i]));
       
    f(i,n)
    {
       int cur_pos = pos[s[i] - 'A'].back();

       f(j,4)
       {
           int o_s = fre_s[i][j];
           int o_t = fre_t[pos[s[i] - 'A'].back()][j];
           
           
           if(o_s > o_t) cur_pos += o_s - o_t;
       }

       pos[s[i] - 'A'].pop_back();
       rr += abs(cur_pos - i);
    }
    
    return rr;
}

void solve()
{
   string s;
   cin >> s;
    
   int n = s.length();
    
   for(auto & x : s)
       if(x == 'N') x = 'B';
       else if(x == 'O') x = 'C';
       else if(x == 'T') x = 'D';
    
   f(i,n) f(j,4) fre_s[i][j] = 0;    
   f(i,n) fre_s[i][s[i] - 'A'] = 1; 
   f(i,n-1) f(j,4) fre_s[i+1][j] += fre_s[i][j];
       
   int res = -1;
   string g = s;
    
   string temp = cc;
   
   do
   {
       string t = "";
       
       for(auto x : temp)
           f(j,fre_s[n-1][x - 'A']) t += x;
     
       int rr = solve(s,t);
       
       if(rr > res)
       {
           res = rr;
           g = t;
       }
       
   }while(next_permutation(all(temp)));
    
   for(auto & x : g)
       if(x == 'B') x = 'N';
       else if(x == 'C') x = 'O';
       else if(x == 'D') x = 'T';
    
   cout << g  << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}