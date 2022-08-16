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
 ll n,k,i,j;
 string s;
    
cin >> n;
    
 ll a[n];
    f(i,n) cin >> a[i];
   
  ll b[n];
    f(i,n) b[i]=a[i];
    sort(b,b+n);
    
  ll val=b[0];  
  ll temp=1,ans=1;
  ll ind=0;
    
    
    f(i,n-1)
    {
        if(b[i]==b[i+1]) temp++;
        else
        {
         if(temp > ans )
         {
          ans=temp;   
          val=b[i];  
         }
          temp=1;  
        }
    }

    if(temp > ans )
         {
          ans=temp;   
          val=b[n-1];    
         }

    f(i,n) if(val==a[i]) {ind=i; break;   }
    
    cout << n-ans << "\n";
    
    f(i,ind)
    { 
        if(a[ind-i-1]==val) continue;
       else if(a[ind-i-1] > val) 
        cout << 2 << " " << ind-i << " " << ind-i+1 << "\n";   
       else cout << 1 << " " << ind-i << " " << ind-i+1 << "\n";
        
         a[ind-i-1]=val;
    }
    
    
    f(i,n-ind-1)
    {
      if(a[ind+i+1]==val) continue;
       else if(a[ind+i+1] > val) 
        cout << 2 << " " << ind+i+2 << " " << ind+i+1 << "\n";   
       else cout << 1 << " " << ind+i+2 << " " << ind+i+1 << "\n";
        
           a[ind+i+1]=val;
    }   
}