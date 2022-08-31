#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
int n,i;
    
cin >> n;

int low = 1;
int high = n;
int ans = n;    

while(low<=high)
{
    
 int mid = (low+high)/2;   
 int sum = 0;
 int temp = n;
    
 while(temp > 0)
 {
  if(temp >= mid)
  {
   temp -= mid; sum+=mid;   
  }
     else { sum+= temp; temp = 0; }
     
  temp -=temp/10;   
 }
    
    if(2*sum>=n) { ans = min(ans,mid); high = mid-1;} 
    else low = mid+1;    
}

cout << ans;
}