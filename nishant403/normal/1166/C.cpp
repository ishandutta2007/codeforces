#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pll pair<int,int>
#define vl vector<int>


signed main()
{
FAST;    
int n,i,j,k,m;
cin >> n;
set<pll> s;
int ans = 0;
int same = 0;
vector<int> a(n);    
map<int,int> mm;
    
f(i,n)
{
 cin >> k;
 a[i]=abs(k);
 if(mm.find(a[i]) != mm.end() && mm[a[i]]==1) same++;   
 mm[a[i]]=1;
}
   
  sort(a.begin(),a.end());
  
 for(i=0;i<n;i++)
 {
 //higher than a[i]/2 
 //lower than a[i]    
    
 int l = 0;
 int r = n-1;
 int high = n-1;
 int low = 0;
 
   while(l<=r)
   {
    int mid = (l+r)/2;   
    if(a[mid] < (a[i]+1)/2) l = mid+1;
    else
    {
     high = min(high,mid);
     r = mid - 1;
    }
   }
     
  l = 0;
  r = n-1;
     
   
   while(l<=r)
   {
    int mid = (l+r)/2;   
    if(a[mid] > a[i]) r = mid-1;
    else
    {
     low = max(low,mid);
     l = mid + 1;
    }
   }
    
  ans +=(low-high);   
 }  
    cout << ans - same;
}