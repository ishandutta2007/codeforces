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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

string gen(int sum)
{
    if(sum == 0) return "";
    
    string res;
    
    while(sum > 0)
    {
        if(sum >= 9)
        {
            res+='9';
            sum-=9;
        }
        else
        {
            res+=('0' + sum);
            sum = 0;
        }
    }
    
    reverse(res.begin(),res.end());
    
    if(res.length() == 1)
    {
        if(res == "9") return "18";
        else return res;
    }
    
    res.back()--;
    
    if(res[0] == '9')
    {
        res = '1' + res;
    }
    else res[0]++;
    
    return res;
}

void solve()
{
   int n,k;
    cin >> n >> k;
   
    string res = "-1";
    
   //Last (i+1) digits will change
   for(int i=0;i<=200;i++)
   {
       //Last digit of x is j. 
       for(int j=0;j<=9;j++)
       {
           int inside = min(10-j,k+1);
           int sum = (inside*9*i);
           f(m,k+1) sum+=(j+m)%10;
           sum+=(k+1)-inside;
           
           if(n < sum) continue;
           
           if((n - sum) % (k+1) == 0)
           {   
               string temp = gen((n-sum)/(k+1));
               
               f(v,i+1) temp+='0';
               
               int sz = temp.length();
               
               temp[sz-1] = '0' + j;
               f(v,i) temp[sz-2-v] = '9';
               
               if(res == "-1") res = temp;
               else if(temp.length() < res.length()) res = temp;
               else if(temp.length() == res.length() && temp < res) res = temp;
           }
       }
   } 
   
   cout << res << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}