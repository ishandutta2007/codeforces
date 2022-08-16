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

const int N = 1e5+10; 
const int lim = (int)1e5;  

int cn[N];
int store[N];
vi last(N,-1);
unordered_map<int,int> fa[N];

int pw(int a,int b,int num)
{
   for(int i=1;i<=b;i++)
   {
     num=num*a;       
     if(num>lim) return 0;
   }
    
   return num; 
}

void dostore(int k)
{
    store[1] = 1;
       
    for(int i=2;i<N;i++)
    {
      store[i] = pw(i,k,(int)1);        
      if(store[i] == 0) return; 
    } 
}

void factorize()
{
    for(int i=2;i<=(int)1e5;i++)
    {
       int dd = i;
        
       while(last[dd] != -1)
       {
           fa[i][last[dd]]++;
           dd/=last[dd];
       }
 
       fa[i][dd]++; 
    }
}

void sieve()
{
    last[0] = last[1] = 0;
    
    for(int i=2;i<N;i++)
    {
      if(last[i] == -1)
          for(int j=i*i;j<N;j+=i) last[j] = i;
    }
}

void solve()
{
  int n,k;
  cin >> n >> k;
    
  dostore(k);  
    
  int a[n];
       
  f(i,n) cin >> a[i];  
  f(i,n) cn[a[i]]++;
     
  int ans = 0;   
     
  for(int i=1;i<=(int)1e5;i++)
  {
    int tmp = 1;
    int flag = 1;
      
    for(auto x : fa[i])
    { 
       int power = x.S;
       power%=k;
        
       if(power == 0) continue; 
        
       tmp = pw(x.F,k-power,tmp);
        
       if(tmp == 0)
       {
         flag = 0; break;   
       }       
    }
      
     if(flag == 0) continue; 
      
     int cnn = 0; 
      
     //now multiply tmp by perfect k powers 
     for(int j=1;;j++)
     {
       if(store[j] == 0) break;
       if(tmp*store[j] > lim) break;    
       cnn+=cn[tmp*store[j]];  
         
       if(tmp*store[j] == i) cnn--;  
     } 
     
     cnn*=cn[i];       
     ans+=cnn;      
  }
     
  cout << ans/2 << "\n"; 
     
}

signed main()
{
    fast;
    
    sieve();
    factorize();
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}