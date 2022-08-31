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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int N = 14;
bool is[N][N];
int go[(1LL<<N)];
int pw[N];
int id = 0;
int dp[14][10000][64];
int ways[(1LL<<N)];
int revv[(1LL<<N)];

int vv;

int get(int i)
{
   int res = 0;
    
   f(j,vv-1) if((i&(1LL<<j))) res+=pw[vv-j-2];
       
   return res;
}

void solve()
{
   pw[0] = 1;
 
   f(i,N-1) pw[i+1] = (pw[i]<<1);
    
   int n;
   cin >> n;
   
   int md = (n/2);
   vv = n - md;
   int full = (1LL<<n)-1;
    
   for(int i=0;i<(1LL<<n);i++) revv[i] = get(i); 
    
   string s;
    
   for(int i=1;i<(1LL<<n);i++)
     if(__builtin_popcount(i) <= 7)
   {
       go[i] = (id++);
   }
   
   f(i,n)
   {
       cin >> s;
       f(j,n) if(s[j] == '1') is[i][j] = 1;
   }
    
   f(i,n) f(j,n) if(i!=j)
       dp[j][go[pw[i]|pw[j]]][is[i][j]]++;
    
   if(n == 2)
   {
       f(i,n) f(j,n) if(i!=j) ways[is[i][j]]++;
       cout << ways[0] <<" "<<ways[1] << '\n';
       return;
   }
       
   for(int i=1;i<(1LL<<n);i++)
   {
       int set = (__builtin_popcount(i));
     
       if(set <= 7 && set >= 3)
   {
       for(int j=0;j<n;j++)
       {
           if((i&pw[j]) == 0) continue;
           
           for(int k=0;k<n;k++)
           {
               if((i&pw[k]) == 0) continue;
               
               for(int l=0;l<(1LL<<(set-2));l++)
               {
                 dp[j][go[i]][(l<<1)|is[j][k]]+=dp[k][go[(i^pw[j])]][l];
               
               }
           }
       }
   }
       
   }
    
    if(n<=7)
    {
       f(k,pw[n-1])
       {
           int temp = 0;
           f(i,n) temp+=dp[i][go[full]][k];
           cout<< temp <<" "; 
       }
        
        return;
    }
    
   for(int i=0;i<(1LL<<n);i++) 
   {
       int set = __builtin_popcount(i);
       if(set != md) continue;
       
       int a1 = i;
       int a2 = (full^a1);
     
       f(j,n) if((a1&pw[j]))
           f(k,n) if((a2&pw[k]))
           
       f(l,64) f(m,64)
       {
          int make = (l<<(n-md)) | revv[m] | (pw[n-md-1]*is[j][k]);
          ways[make]+=dp[j][go[a1]][l]*dp[k][go[a2]][m];
       }
   }
   
   for(int i=0;i<pw[n-1];i++) cout<<ways[i] <<" ";
}

signed main()
{
    fast;
    solve();
}