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

void solve()
{
int n;
cin >> n;
    
int a[n];
int ans = 0;    
    
f(i,n) cin >> a[i];
    
sort(a,a+n);
    
int a1=0,a2=0,a3=0;    

a1 = a[n-1];    
 
    
int f1=0,f2=0,f3=0;
    
if(a[n-1] % 30 == 0)    
{
 for(int i=n-1;i>=0;i--)
 {
     if(a[i] == a[n-1]/2) f1=1;
     if(a[i] == a[n-1]/5) f2=1;
     if(a[i] == a[n-1]/3) f3=1;
 }
    
 if(f1&&f2&&f3) ans = a[n-1]/2 + a[n-1]/3 + a[n-1]/5;   
}
    
for(int i=n-1;i>=0;i--)
{
    if(a1 % a[i] != 0) { a2=a[i]; break; }  
}
   
for(int i=n-1;i>=0;i--)
{
    if(a1 % a[i] != 0 && a2 % a[i] !=0) { a3=a[i]; break; }  
}    
    
cout << max(ans,a1+a2+a3) << "\n";   
}


signed main()
{
    fast;
    int t;
    cin >> t;
    
    while(t--)
    solve();
}