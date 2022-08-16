#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define f(i,n) for(int i=0;i<n;i++)
typedef long long ll;


void matrixmult(vector<vector<ll> > &a,vector<vector<ll> > &b)
{
    
  ll x,y,z;
  x=a[0].size();
  y=a.size();
  z=b.size();
  
  vector<ll> t (z,0);
  vector< vector<ll> > c(x,t);
  
  f(i,x) f(j,z) f(k,y) c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%M) % M;
 
  f(i,x) f(j,z) b[i][j]=c[i][j];
    
}

int main()
{
      ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    ll n,m;
    cin >> n >> m;
    
    vector<ll> row(m,0);
    vector<vector<ll>> recur(m,row);
    
   vector<ll> id(m,0);
   vector<vector<ll>> ident(m,id);
   
   f(i,m) f(j,m) if(i==j) ident[i][j]=1;
   
  
  f(i,m-1) recur[i][i+1]=1;
  
  recur[m-1][0]=1;
  recur[m-1][m-1]=1;
 
 while(n)
 {
     if(n&1) matrixmult(recur,ident);
    matrixmult(recur,recur);
    n/=2; 
 }
 
ll ans=0;
f(i,m) ans=(ans+ident[0][i])%M;

 cout << ans;
    
}