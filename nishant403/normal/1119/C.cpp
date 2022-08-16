#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<long> 

int main()
{
 fast;   
 ll n,k,i,h,j,m,ans=0;
 string s;
    
 cin >> n >> m;
    
 vl t(m,0);
 vector<vl> A(n,t),B(n,t),C(n,t);
    
 f(i,n) f(j,m) cin >> A[i][j];
 f(i,n) f(j,m) cin >> B[i][j];
    
 f(i,n) f(j,m) C[i][j]=A[i][j]^B[i][j];
    
 f(i,n)
 {
  ll sum=0;   
     f(j,m) sum+=C[i][j];
     
     if(sum%2)
     {
      cout <<"No\n";
         return 0;
     }
 }
    
    f(i,m)
 {
  ll sum=0;   
     f(j,n) sum+=C[j][i];
     
     if(sum%2)
     {
      cout <<"No\n";
         return 0;
     }
 }
    
    
    
    
    
    cout << "Yes\n";
}