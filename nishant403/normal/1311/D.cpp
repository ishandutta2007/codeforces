#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e4+2;
vi dd[N];

void sieve()
{
    for(int i=1;i<=20000;i++)
        for(int j=i;j<=20000;j+=i)
            dd[j].pb(i);
}


void solve()
{
   int a,b,c;
   cin >> a >> b >> c;
    
   int A,B,C;
    
   A = B = C = -1;
    
   int run =0;
   int res = 1e7;  
    
   if(a > c) swap(a,b);
   if(b > c) swap(b,c);
   if(a > b) swap(a,b);
  
   for(int mid = 1;mid <= 20000;mid++)
   {
        int sum = abs(b-mid);
        int mn = 1e7;
        int val = -1;
        int mn2 = 1e7;
        int val2 = -1;
       
       for(auto z : dd[mid])
       {
           if(abs(z-a) < mn)
           {
               mn = abs(z-a);
               val = z;
           }
       }
       
       for(int j=mid;j<=20000;j+=mid)
       {
           if(abs(j-c) < mn2)
           {
               mn2 = abs(j-c);
               val2 = j;
           }
       }
       
       if(res > mn + sum + mn2)
       {
           res = mn + sum + mn2;
           A = val;
           B = mid;
           C = val2;
       }
   } 
    
   cout << res << '\n';
    
   cout <<A <<" "<<B<<" "<<C<<'\n';
}

signed main()
{
    fast;
    
    sieve();
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}