#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MOD = 31607;

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

//Fast Walsh Hadamard Transform

//XOR [  1 1 ]   //AND [ 0 1 ]  //OR  [ 1 1 ]
//    [ 1 -1 ]         [ 1 1 ]        [ 1 0 ]

void FWHT(vector<int> & P,bool inv = false,int N = (1LL<<23))
{
    for(int len=1;len<N;len<<=1)
        for(int i=0;i<N;i+=(len<<1))
        f(j,len)
    {
        int a = P[i+j];
        int b = P[i+j+len];
    
       if(inv == true)
       {
        P[i+j] = b;
        P[i+j+len] = (a + MOD - b)%MOD; 
       }
       else
       {
        P[i+j] = (a + b)%MOD;
        P[i+j+len] = a; 
       }
    }
}

const int N = 23;

int n,a[N][N],b[N][N],c[N][N];

vector<int> cur(1<<N),temp(1<<N);

vector<int> go(1<<21);

signed main()
{
   cin >> n;
   f(i,n) f(j,n) cin >> a[i][j]; 
   
   f(i,n) f(j,n) a[i][j] = (a[i][j]*mod_pow(10000,MOD - 2))%MOD;
   f(i,n) f(j,n) b[i][j] = (1 - a[i][j] + MOD)%MOD;
   f(i,n) f(j,n) c[i][j] = (b[i][j]*mod_pow(a[i][j],MOD-2))%MOD;    
    
   int tot = (1<<(n+2)); 
    
   f(i,tot) cur[i] = 1;
    
   f(i,n)
   {
      f(j,tot) temp[j] = 0;
      
      go[0] = 1;
      f(j,n) go[0] = (go[0]*a[i][j])%MOD;
      
      for(int j=1;j<(1<<n);j++)
      {
          int bt = 32 - __builtin_clz(j) - 1;
          go[j] = go[j^(1<<bt)]*c[i][bt];
          go[j] %= MOD;
      }
      
      f(j,(1<<n))
      {   
          if(j == 0) continue;
           
          int f1 = ((j >> i) & 1);
          int f2 = ((j >> (n-i-1)) & 1);
           
          int msk = (j<<2) + (f1<<1) + f2;
          
          temp[msk] = go[j];
      }
       
        for(int len=1;len<tot;len<<=1)
        for(int v=0;v<tot;v+=(len<<1))
        f(j,len)
        {
            int x = temp[v+j];
            int y = temp[v+j+len];
            
            temp[v+j] = (x+y >= MOD ? x + y - MOD : x + y);
            temp[v+j+len] = x; 
        }
       
       f(j,tot) cur[j] = (cur[j]*temp[j])%MOD;
   }
       
   FWHT(cur,1,tot);
    
   int res = cur[tot - 1]; 
   res = (1 + MOD - res)%MOD;
   cout << res;
}